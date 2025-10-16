import java.util.*;
public class FractionalKnapSack{
    public static void main(String args[]){

        int val[] = {60, 100, 120};
        int weight[] = {10, 20, 30};
        int maxWeight = 50;

        double ratio[][] = new double[val.length][2];

        // creating a 2D array containing 2 columns
        // 0th col -> stores idx
        // 1st col -> stores ratio
 
        for(int i = 0; i<val.length; i++){
            ratio[i][0] = i;
            ratio[i][1] = val[i]/(double)weight[i];

        }

        // this sorts the arr in ascending order
        Arrays.sort(ratio, Comparator.comparingDouble(o -> o[1]));

        int capacity = maxWeight;
        int finalVal = 0;

        // getting the elements in descending order
        for(int i=ratio.length-1; i>=0; i--){
            int idx = (int)ratio[i][0];
            if(capacity >= weight[idx]){
                finalVal += val[idx];
                capacity -= weight[idx];
            }else{
                //include fractional item
                finalVal += (ratio[i][1] * capacity);
                capacity = 0;
                break;
            }
        }

        System.out.println("final value = " + finalVal);

    }
}