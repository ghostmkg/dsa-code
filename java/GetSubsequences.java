
import java.util.*;

class GetSubsequences{
    
    public static void helper(String s,String p,List<String> ans){

        if(s.length()==0){
            ans.add(p);
            return;
        }

        helper(s.substring(1), p+s.charAt(0), ans);
        helper(s.substring(1), p, ans);
    }
    public static void main(String[] args){
       Scanner sc=new Scanner(System.in);
       String s=sc.nextLine();

       List<String> ans=new ArrayList<>();
       helper(s,"",ans);
       System.out.print(ans);
    }
}
