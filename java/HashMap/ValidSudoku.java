import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        
        if (board == null || board.length != 9 || board[0].length != 9) {
            return false;
        }

        List<Set<Character>> rows = new ArrayList<>();
        List<Set<Character>> cols = new ArrayList<>(); 
        List<Set<Character>> boxes = new ArrayList<>();

        for (int i = 0; i < 9; i++) {
            rows.add(new HashSet<>());
            cols.add(new HashSet<>());
            boxes.add(new HashSet<>());
        }

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') continue;

                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows.get(r).contains(val) ||
                    cols.get(c).contains(val) ||
                    boxes.get(boxIndex).contains(val)) {
                    return false;
                }

                rows.get(r).add(val);
                cols.get(c).add(val);
                boxes.get(boxIndex).add(val);
            }
        }

        return true;
    }
}
