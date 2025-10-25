/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

function isValid(s) {
    // Write your code here
    
    let chFreq = {};
    for(let ch of s){
        chFreq[ch] = (chFreq[ch] || 0) + 1 ;
    }
    
    let freqCount = {};
    for (let count of Object.values(chFreq)){
        freqCount[count] = (freqCount[count] || 0) + 1;
    }

    let freqKey = Object.keys(freqCount).map(Number);

    if (freqKey.length === 1) 
        return "YES";


   if (freqKey.length === 2) {
        const [freq1, freq2] = freqKey;
        const [count1, count2] = [freqCount[freq1], freqCount[freq2]];


        if((freq1 === 1 && count1 === 1)|| (freq2 === 1 && count2 === 1))
            return "YES";
        if((Math.abs(freq1 - freq2) === 1) && (count1 === 1 || count2 === 1))
            return "YES";
   }
   return "NO";
}


let res = isValid("aaaaabc");
console.log(res);
