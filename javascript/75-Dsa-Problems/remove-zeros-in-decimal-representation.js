/**
 * @param {number} n
 * @return {number}
 */
var removeZeros = function(n) {
       return Number(String(n).replace(/0/g, ''));
};