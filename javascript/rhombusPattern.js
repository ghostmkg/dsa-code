/*
Question: Print a solid rhombus pattern of stars.

Example:
Input: n = 5
Output:
        * * * * * 
      * * * * * 
    * * * * * 
  * * * * * 
* * * * * 
*/

function printRhombus(n) {
  for (let i = 1; i <= n; i++) {
    let row = "";

    // spaces
    for (let j = 1; j <= n - i; j++) {
      row += "  "; // double spaces for alignment
    }

    // stars
    for (let j = 1; j <= n; j++) {
      row += "* ";
    }

    console.log(row); // print row
  }
}

printRhombus(5);
