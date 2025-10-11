// this code is to Convert Integer to the Sum of Two No-Zero Integers
const readline = require("readline");

    function getNoZeroIntegers(n){
        function noZero(x){
            while(x>0){
                if (x % 10===0) return false;
                x=Math.floor(x/10);
            }
            return true;
        }
    

    for(let a=1;a<n;a++){
        let b= n-a;
         if (noZero(a) && noZero(b)) {
            return [a, b];
        }
    }
    return[];
 }

 const rl=readline.createInterface({
    input:process.stdin,
    output:process.stdout
 });

 rl.question("Enter a number: ",(answer) =>{
    const n = parseInt(answer);
    const result= getNoZeroIntegers(n);
    console.log("Results",result);
    rl.close();
 });