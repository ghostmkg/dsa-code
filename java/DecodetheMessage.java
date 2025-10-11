// LeetCode 2325. Decode the Message
import java.util.HashMap;

public class DecodetheMessage {
    public String decodeMessage(String key, String message) {
        String Cleankey=key.replaceAll("\\s+","");

        HashMap<Character,Character> map=new HashMap<>();
        StringBuilder sb=new StringBuilder();

        int alphacount=0;

        // this to maping the letters
        for(char c: Cleankey.toCharArray()){
            if(!map.containsKey(c)){
                map.put(c,(char)('a'+ alphacount++));
            }
            else if(alphacount==26){
                break;
            }
        }

        // to assign the values
        for(char c :message.toCharArray()){
            if(c == ' '){
                sb.append(c);
            }
            else{
                sb.append(map.get(c));
            }
        }
        return sb.toString(); 
    }
}

// Example 1:

// Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
// Output: "this is a secret"
// Explanation: The diagram above shows the substitution table.
// It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".

// Example 2:

// Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
// Output: "the five boxing wizards jump quickly"
// Explanation: The diagram above shows the substitution table.
// It is obtained by taking the first appearance of each letter in "eljuxhpwnyrdgtqkviszcfmabo".
 
// Constraints:

// 26 <= key.length <= 2000
// key consists of lowercase English letters and ' '.
// key contains every letter in the English alphabet ('a' to 'z') at least once.
// 1 <= message.length <= 2000
// message consists of lowercase English letters and ' '.