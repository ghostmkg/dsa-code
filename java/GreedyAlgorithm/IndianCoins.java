import java.util.*;

public class IndianCoins{
    public static void main(String args[]){

        Integer coins[] = {2000, 500, 100, 50, 20, 10, 5, 2, 1};

        Arrays.sort(coins, Comparator.reverseOrder());

        int coinsLength = 0;
        int coinsToGive = 590;
        ArrayList<Integer> ans = new ArrayList<>();

        for(int i=0; i<coins.length; i++){
            if(coinsToGive >= coins[i]){
                while(coins[i] <= coinsToGive){
                    coinsToGive -= coins[i];
                    ans.add(coins[i]);
                    coinsLength++;
                }
            }
        }


        System.out.println(coinsLength);

        // we can also get which which coins were selected

        System.out.print("The min number of coins to give: ");
        for(int i=0; i<ans.size(); i++){
            System.out.print(+ans.get(i) + " ");
        }
    }

}