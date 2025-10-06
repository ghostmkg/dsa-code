// Palindrom => racecar, noon, madam, 1223221, etc

import java.util.*;

public class Palindrome {
    public static boolean isPalindrome(String str) {
        for(int i=0; i<str.length()/2; i++) {
            int n = str.length();
            if(str.charAt(i) == str.charAt(n - 1 - i)) {
                return true;
            } 
 
        }
        return false;
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        System.out.print("Enter String: ");
        String str = scn.nextLine();
       System.out.println(isPalindrome(str)); 


    }
}
