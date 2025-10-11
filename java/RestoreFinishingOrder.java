// LeetCode 3668. Restore Finishing Order
import java.util.ArrayList;

public class RestoreFinishingOrder {

    public int[] recoverOrder(int[] order, int[] friends) {
       ArrayList<Integer> ans=new ArrayList<>(); 
       ArrayList<Integer> Al=new ArrayList<>();
       for(int friend :friends){
        Al.add(friend);
       }

       for(int num:order){
         if(Al.contains(num)){
            ans.add(num);
          }
       }
       int[] res=new int[ans.size()];

       for(int i=0;i<ans.size();i++){
         res[i]=ans.get(i);
       }

       return res;
    }
}

// Example 1:

// Input: order = [3,1,2,5,4], friends = [1,3,4]
// Output: [3,1,4]

// Explanation:
// The finishing order is [3, 1, 2, 5, 4]. Therefore, the finishing order of your friends is [3, 1, 4].

// Example 2:

// Input: order = [1,4,5,3,2], friends = [2,5]
// Output: [5,2]

// Explanation:
// The finishing order is [1, 4, 5, 3, 2]. Therefore, the finishing order of your friends is [5, 2].

