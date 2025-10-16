import java.util.*;

// DO THIS QUESTION AGAIN AND STORE ANOTHER COLUMN FOR STORING IDX AS WELL
// TC -> O(nlogn)
public class MaxLengthChainOfPairs{
    public static void main(String args[]){

        int pairs[][] = {
                          {5, 24},
                          {39, 60},
                          {5, 28},
                          {27, 40},
                          {50, 90}
                        };

        Arrays.sort(pairs, Comparator.comparingDouble(o -> o[1]));

        // always select the first chain
        int chainLength = 1;

        // also store the last end, it will be used for comparison
        int chainEnd = pairs[0][1];

        for(int i = 1; i<pairs.length; i++){
            if(chainEnd < pairs[i][0]){
                chainLength++;
                chainEnd = pairs[i][1];
            }
        }

        System.out.println("Max chain length: " + chainLength);
    }
}