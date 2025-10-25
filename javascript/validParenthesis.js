// TODO: Implement this method
function validParenthesis(s) {
    let st = new Stack();
    for(let ch of s){
        if(ch === '(' || ch === '{' || ch === '['){
            st.push(ch);
        } else {
            if(st.isEmpty()){
                return false;
            }
            if(ch === ')' && st.pop() !== '('){
                return false;
            }
            if(ch === '}' && st.pop() !== '{'){
                return false;
            }
            if(ch === ']' && st.pop() !== '['){
                return false;
            }
        }
    }
    if(!st.isEmpty())
        return false
    return true;
}

