#include <bits/stdc++.h>
#include <thread>
#include <atomic>
using namespace std;

/*
  Sudoku with DLX (Dancing Links) solver + generator
  - Solves standard 9x9 Sudoku by exact cover formulation (constraints: cell, row, col, box)
  - Generator: starts from a full valid board then removes clues while ensuring uniqueness.
  - Multithreaded attempt for generation: try multiple removal strategies.
*/

// -------------------- Utility: RNG --------------------
std::mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
int rnd_int(int a, int b){ uniform_int_distribution<int> dist(a,b); return dist(rng); }

// -------------------- DLX Implementation --------------------
// Based on Knuth's Dancing Links structure for exact cover
struct DLX {
    struct Node {
        int row, col;
        Node *L, *R, *U, *D;
        Node(int r=0,int c=0): row(r), col(c), L(this), R(this), U(this), D(this) {}
    };

    int nCols;
    vector<int> colSize;
    Node* header;
    vector<Node*> colHeader;
    vector<Node*> nodes; // owning pointers for cleanup

    DLX(int m): nCols(m), colSize(m,0), header(new Node(-1,-1)), colHeader(m,nullptr) {
        nodes.push_back(header);
        // create column headers and link them horizontally
        Node* prev = header;
        for(int c=0;c<m;c++){
            Node* ch = new Node(-1,c);
            nodes.push_back(ch);
            colHeader[c]=ch;
            prev->R = ch; ch->L = prev;
            prev = ch;
        }
        prev->R = header; header->L = prev;
        // vertical links initially point to themselves
    }

    ~DLX(){
        for(auto p : nodes) delete p;
    }

    void add_row(int r, const vector<int>& cols){
        Node* first = nullptr;
        Node* prev = nullptr;
        for(int c : cols){
            Node* column = colHeader[c];
            Node* nd = new Node(r,c);
            nodes.push_back(nd);
            // vertical insert at bottom of column
            nd->D = column;
            nd->U = column->U;
            column->U->D = nd;
            column->U = nd;
            colSize[c]++;
            if(!first) first = nd;
            if(prev){
                prev->R = nd;
                nd->L = prev;
            }
            prev = nd;
        }
        // close the circular row
        if(first && prev){
            first->L = prev;
            prev->R = first;
        }
    }

    void cover(Node* colNode){
        // remove column header
        colNode->R->L = colNode->L;
        colNode->L->R = colNode->R;
        // for each row in column, remove nodes in that row from their columns
        for(Node* i = colNode->D; i != colNode; i = i->D){
            for(Node* j = i->R; j != i; j = j->R){
                j->D->U = j->U;
                j->U->D = j->D;
                colSize[j->col]--;
            }
        }
    }

    void uncover(Node* colNode){
        for(Node* i = colNode->U; i != colNode; i = i->U){
            for(Node* j = i->L; j != i; j = j->L){
                colSize[j->col]++;
                j->D->U = j;
                j->U->D = j;
            }
        }
        colNode->R->L = colNode;
        colNode->L->R = colNode;
    }

    // choose column with smallest size (heuristic)
    Node* choose_column(){
        Node* best = nullptr;
        int bestSize = INT_MAX;
        for(Node* c = header->R; c != header; c = c->R){
            if(colSize[c->col] < bestSize){
                bestSize = colSize[c->col];
                best = c;
            }
        }
        return best;
    }

    // solution callback: store row indices chosen
    bool solve(vector<int>& solution, int maxSolutions = 2){
        atomic<int> sols_found(0);
        vector<Node*> stack;
        function<void()> search = [&](){
            // recursive lambda not directly possible; use std::function with captures
        };
        // we'll implement recursive function as std::function
        function<void()> dfs = [&](){
            if(header->R == header){
                // found a solution
                vector<int> rows;
                for(auto nd : stack) rows.push_back(nd->row);
                // copy to solution if first found
                if(sols_found == 0){
                    solution = rows;
                }
                sols_found++;
                return;
            }
            if(sols_found >= maxSolutions) return;
            Node* col = choose_column();
            if(!col) return;
            cover(col);
            for(Node* r = col->D; r != col; r = r->D){
                stack.push_back(r);
                for(Node* j = r->R; j != r; j = j->R) cover(colHeader[j->col]);
                dfs();
                for(Node* j = r->L; j != r; j = j->L) uncover(colHeader[j->col]);
                stack.pop_back();
                if(sols_found >= maxSolutions) break;
            }
            uncover(col);
        };

        dfs();
        return sols_found > 0;
    }

    // specialized solver that counts solutions up to limit
    int count_solutions(int limit=2){
        atomic<int> sols_found(0);
        vector<Node*> stack;
        function<void()> dfs = [&](){
            if(sols_found >= limit) return;
            if(header->R == header){
                sols_found++;
                return;
            }
            Node* col = choose_column();
            if(!col) return;
            cover(col);
            for(Node* r = col->D; r != col; r = r->D){
                stack.push_back(r);
                for(Node* j = r->R; j != r; j = j->R) cover(colHeader[j->col]);
                dfs();
                for(Node* j = r->L; j != r; j = j->L) uncover(colHeader[j->col]);
                stack.pop_back();
                if(sols_found >= limit) break;
            }
            uncover(col);
        };
        dfs();
        return (int)sols_found;
    }
};

// -------------------- Sudoku exact-cover mapping --------------------
// For 9x9 Sudoku, there are 9x9x9 possible assignments (row, col, digit)
// Constraints (4 types):
// 1) Cell constraint: each cell (r,c) must have a digit (81 constraints)
// 2) Row constraint: each row r must contain digit d exactly once (81)
// 3) Col constraint: each column c must contain digit d exactly once (81)
// 4) Box constraint: each 3x3 box b must contain digit d exactly once (81)
// Total columns: 324
// Row index mapping: r*81 + c*9 + d in [0,728]

inline int cell_constraint(int r,int c){ return r*9 + c; }
inline int row_constraint(int r,int d){ return 81 + r*9 + d; }
inline int col_constraint(int c,int d){ return 162 + c*9 + d; }
inline int box_constraint(int b,int d){ return 243 + b*9 + d; }
inline int box_index(int r,int c){ return (r/3)*3 + (c/3); }

struct Sudoku {
    array<int,81> A; // 0 for blank, else 1..9
    Sudoku(){ A.fill(0); }
    string to_string_board() const {
        string s;
        for(int i=0;i<81;i++){
            s.push_back((A[i]==0 ? '.' : char('0' + A[i])));
            if((i+1)%9==0) s.push_back('\n');
        }
        return s;
    }
};

// Build DLX matrix for Sudoku; if a cell already has a digit, include only that row
unique_ptr<DLX> build_dlx_from_board(const Sudoku& board){
    auto dlx = make_unique<DLX>(324);
    // For each possible assignment r,c,d -> add row satisfying 4 constraints
    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){
            int given = board.A[r*9 + c];
            for(int d=1; d<=9; d++){
                if(given!=0 && given!=d) continue;
                vector<int> cols;
                cols.push_back(cell_constraint(r,c));
                cols.push_back(row_constraint(r,d-1));
                cols.push_back(col_constraint(c,d-1));
                cols.push_back(box_constraint(box_index(r,c),d-1));
                int row_id = r*81 + c*9 + (d-1);
                dlx->add_row(row_id, cols);
            }
        }
    }
    // Link column headers' U pointers properly (they were self-pointing if no nodes)
    // Actually add_row set U/D appropriately.
    return dlx;
}

// Solve DLX and return solved board (first solution). If multiple solutions exist, can detect.
bool solve_sudoku_with_dlx(const Sudoku& puzzle, Sudoku& solved, int maxSolutions=2, int* out_num_solutions=nullptr){
    auto dlx = build_dlx_from_board(puzzle);
    vector<int> solutionRows;
    bool has = dlx->solve(solutionRows, maxSolutions);
    if(!has){ if(out_num_solutions) *out_num_solutions = 0; return false; }
    // if only need to count solutions:
    if(out_num_solutions && maxSolutions>1){
        int cnt = dlx->count_solutions(maxSolutions);
        *out_num_solutions = cnt;
    }
    // parse first solution rows into board
    solved = Sudoku();
    for(int rowid : solutionRows){
        int r = rowid / 81;
        int rem = rowid % 81;
        int c = rem / 9;
        int d = (rem % 9) + 1;
        solved.A[r*9 + c] = d;
    }
    return true;
}

// A faster deterministic solver for getting a complete valid board: backtracking with bit masks
bool backtrack_fill(array<int,81>& board, array<int,9>& rowMask, array<int,9>& colMask, array<int,9>& boxMask, int cell=0){
    // find next empty cell
    while(cell < 81 && board[cell] != 0) ++cell;
    if(cell==81) return true;
    int r = cell / 9, c = cell % 9, b = box_index(r,c);
    int used = rowMask[r] | colMask[c] | boxMask[b];
    for(int d=1; d<=9; ++d){
        int bit = 1 << d;
        if(used & bit) continue;
        board[cell] = d;
        rowMask[r] |= bit;
        colMask[c] |= bit;
        boxMask[b] |= bit;
        if(backtrack_fill(board, rowMask, colMask, boxMask, cell+1)) return true;
        board[cell] = 0;
        rowMask[r] &= ~bit;
        colMask[c] &= ~bit;
        boxMask[b] &= ~bit;
    }
    return false;
}

// generate a full solved board by randomized backtracking
Sudoku generate_full_board(){
    Sudoku s;
    array<int,81> board; board.fill(0);
    array<int,9> rowMask; rowMask.fill(0);
    array<int,9> colMask; colMask.fill(0);
    array<int,9> boxMask; boxMask.fill(0);

    // fill cells in random order to get varied boards
    vector<int> order(81);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);

    // We'll perform randomized backtracking using simple approach:
    function<bool(int)> fill_pos = [&](int idx){
        if(idx==81) return true;
        int cell = idx; // deterministic order 0..80 for simplicity
        int r = cell/9, c = cell%9, b = box_index(r,c);
        // candidates 1..9 shuffled
        array<int,9> cand; iota(cand.begin(), cand.end(), 1);
        shuffle(cand.begin(), cand.end(), rng);
        for(int d : cand){
            int bit = 1<<d;
            if((rowMask[r] & bit) || (colMask[c] & bit) || (boxMask[b] & bit)) continue;
            board[cell] = d;
            rowMask[r] |= bit; colMask[c] |= bit; boxMask[b] |= bit;
            if(fill_pos(idx+1)) return true;
            board[cell] = 0;
            rowMask[r] &= ~bit; colMask[c] &= ~bit; boxMask[b] &= ~bit;
        }
        return false;
    };

    // call fill
    bool ok = fill_pos(0);
    if(!ok) {
        // fallback deterministic fill (shouldn't usually happen)
        fill_pos(0);
    }
    for(int i=0;i<81;i++) s.A[i] = board[i];
    return s;
}

// -------------------- Puzzle generator --------------------
struct Generator {
    Sudoku solution;
    Sudoku puzzle;
    int target_removed; // attempt to remove this many cells, lower => harder puzzle (fewer clues)
    int min_clues;
    Generator(): target_removed(60), min_clues(17) {} // default: remove ~60 (so ~21 clues remain)

    // Attempt to create a puzzle by removing clues while maintaining unique solution
    // removalOrder: vector of indices indicating the order to try removing
    bool attempt_generation(const Sudoku& full, vector<int> removalOrder, Sudoku& out_puzzle){
        Sudoku cur = full;
        // Initially all filled
        for(int idx : removalOrder){
            int backup = cur.A[idx];
            cur.A[idx] = 0;
            // check uniqueness: build DLX and count solutions up to 2
            int num_sols = 0;
            Sudoku tmp;
            // build DLX
            auto dlx = build_dlx_from_board(cur);
            num_sols = dlx->count_solutions(2);
            if(num_sols != 1){
                // can't remove this one, restore
                cur.A[idx] = backup;
            } else {
                // removal accepted
                // continue
            }
            int clues_left = 0;
            for(int i=0;i<81;i++) if(cur.A[i]!=0) clues_left++;
            if(clues_left <= min_clues) break;
        }
        out_puzzle = cur;
        // ensure uniqueness final
        auto dlx2 = build_dlx_from_board(out_puzzle);
        int final_count = dlx2->count_solutions(2);
        return final_count == 1;
    }

    // Multi-threaded generation: spawn threads, each tries a different random removal order; first that returns success is used
    Sudoku generate(int threads_count = 1){
        solution = generate_full_board();
        puzzle = solution;
        // prepare index vector
        vector<int> base(81); iota(base.begin(), base.end(), 0);
        atomic<bool> found(false);
        mutex out_m;
        Sudoku best;
        vector<thread> threads;
        int attempts_per_thread = 8;
        for(int t=0;t<threads_count;t++){
            threads.emplace_back([&,t](){
                for(int attempt=0; attempt<attempts_per_thread && !found.load(); ++attempt){
                    vector<int> order = base;
                    shuffle(order.begin(), order.end(), rng);
                    Sudoku candidate;
                    if(attempt_generation(solution, order, candidate)){
                        // accept
                        lock_guard<mutex> lk(out_m);
                        if(!found.load()){
                            best = candidate;
                            found.store(true);
                            return;
                        }
                    }
                }
            });
        }
        for(auto &th : threads) if(th.joinable()) th.join();
        if(found){
            puzzle = best;
            return puzzle;
        } else {
            // fallback: single-threaded deterministic removal
            vector<int> order = base;
            // try removing corners/edges first to get sparser puzzle
            sort(order.begin(), order.end(), [](int a,int b){
                int ra=a/9, ca=a%9, rb=b/9, cb=b%9;
                int da = min({ra,8-ra,ca,8-ca});
                int db = min({rb,8-rb,cb,8-cb});
                return da < db;
            });
            attempt_generation(solution, order, puzzle);
            return puzzle;
        }
    }
};

// -------------------- IO Helpers --------------------
bool parse_board_from_string(const string& s, Sudoku& out){
    string cleaned;
    for(char ch : s){
        if(ch=='.' || ch=='0' || (ch>='1'&&ch<='9')) cleaned.push_back(ch);
    }
    if(cleaned.size() < 81) return false;
    for(int i=0;i<81;i++){
        char ch = cleaned[i];
        if(ch=='.' || ch=='0') out.A[i] = 0;
        else out.A[i] = ch - '0';
    }
    return true;
}

void print_board_console(const Sudoku& b){
    for(int r=0;r<9;r++){
        if(r%3==0) cout << "+-------+-------+-------+\n";
        for(int c=0;c<9;c++){
            if(c%3==0) cout << "| ";
            int v = b.A[r*9+c];
            if(v==0) cout << ". ";
            else cout << v << ' ';
        }
        cout << "|\n";
    }
    cout << "+-------+-------+-------+\n";
}

// -------------------- Main CLI --------------------
int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(argc < 2){
        cout << "Usage:\n  " << argv[0] << " solve      # read 81-char puzzle from stdin (0 or . for blanks)\n  " << argv[0] << " generate [threads]\n";
        return 0;
    }
    string cmd = argv[1];
    if(cmd == "solve"){
        // read everything from stdin
        string input((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
        Sudoku puzzle;
        if(!parse_board_from_string(input, puzzle)){
            cerr << "Failed to read puzzle (need at least 81 digits/dots/zeros)\n";
            return 1;
        }
        cout << "Input puzzle:\n";
        print_board_console(puzzle);
        Sudoku solved;
        int num_sols = 0;
        bool ok = solve_sudoku_with_dlx(puzzle, solved, 2, &num_sols);
        if(!ok){
            cout << "No solution found.\n";
            return 0;
        }
        cout << "Number of solutions (up to 2): " << num_sols << "\n";
        if(num_sols >= 2){
            cout << "Puzzle has multiple solutions; first solution shown:\n";
        } else {
            cout << "Unique solution:\n";
        }
        print_board_console(solved);
        return 0;
    } else if(cmd == "generate"){
        int threads = 1;
        if(argc >= 3){
            try { threads = stoi(argv[2]); }
            catch(...) { threads = 1; }
            threads = max(1, min(32, threads));
        }
        cout << "Generating full board...\n";
        Generator g;
        g.min_clues = 17; // rarely solvable below 17
        cout << "Starting generation with " << threads << " threads (this may take a few seconds)...\n";
        Sudoku puz = g.generate(threads);
        cout << "Solution (completed board):\n";
        print_board_console(g.solution);
        cout << "\nGenerated puzzle (0 = blank):\n";
        print_board_console(puz);
        cout << "\nPuzzle in single-line (81 chars, 0 for blank):\n";
        for(int i=0;i<81;i++) cout << (puz.A[i]==0 ? '0' : char('0'+puz.A[i]));
        cout << "\n";
        return 0;
    } else {
        cerr << "Unknown command: " << cmd << "\n";
        return 1;
    }
}
