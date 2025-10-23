function removeBackspace(str){
    let st = [];
    for(let i=0;i<str.length; i++){
        if(str[i] !== '#'){
            st.push(str[i]);
        } else {
            st.pop(str[i-1]);
        }
    }
    return st.join("")
}
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
function backspaceStringCompare(s, t) { 
    console.log(removeBackspace(t))
    console.log(removeBackspace(s))

    if(removeBackspace(s) == removeBackspace(t)){
        return true;
    } else {
        return false;
    }
}
console.log(backspaceStringCompare('as#sddff#', 'aa#sddf'));
