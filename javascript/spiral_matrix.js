let mtrx = [[1, 2, 3, 4],
[4, 5, 6, 7],
[7, 8, 9, 10],
[10, 11, 12, 13]];

class Matrix {
    #mat = [];
    constructor(matrix = []) {
        this.#mat = matrix;
    }

    showMatrix() {
        console.log(this.#mat);
    }



    addRow(row = []) {
        this.#mat.push(row);
        this.#padRows();
    }

    #padRows() {
        let max_row_length = 0;

        for (let i = 0; i < this.#mat.length; i++) {
            if (this.#mat[i].length > max_row_length) {
                max_row_length = this.#mat[i].length
            }
        }

        for (let i = 0; i < this.#mat.length; i++) {
            while (this.#mat[i].length < max_row_length) {
                this.#mat[i].push(0);
            }
        }

        return max_row_length;
    }

    getMatrix() {
        return this.#mat;
    }

    spiralTraversal(show_traversal=false) {
        let res = [];
        let mtrx = this.#mat;

        let top = 0;
        let bottom = mtrx.length;
        let left = 0;
        let right = mtrx[0].length;

        while (top < bottom && left < right) {
            for (let i = left; i < right; i++) {
                res.push(mtrx[top][i]);
            }
            top += 1;

            for (let i = top; i < bottom; i++) {
                res.push(mtrx[i][right - 1]);
            }
            right -= 1;

            if (top < bottom) {

                for (let i = right - 1; i >= left; i--) {
                    res.push(mtrx[bottom - 1][i]);
                }
                bottom -= 1;

            }

            if (left < right) {
                for (let i = bottom - 1; i >= top; i--) {
                    res.push(mtrx[i][left]);
                }
                left += 1;
            }
        }

        if(show_traversal){
            //Gotta make it more beautiful with actual spiral
            console.log(res.join(" -> "));
        }

        return res;
    }
}

let m = new Matrix();

m.addRow([0, 0, 0, 0, 0, 0,])
m.addRow([1, 2, 3, 4, 5])
m.addRow([1, 2, 3, 4])
m.addRow([1, 2, 3, 4])

console.log(m.spiralTraversal(true))