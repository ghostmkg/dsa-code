//LeetCode 3100. Water Bottles II

public class WaterBottlesII {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
      int Drinked=0,Empty=0;
        while(numBottles>0){
           Drinked+=numBottles;
           Empty+=numBottles;
           numBottles=0;
           if(Empty>=numExchange){
            numBottles++;
           }
           Empty-=numExchange;
           numExchange++;
        }
        return Drinked;  
    }
}


// Example 1:

// Input: numBottles = 13, numExchange = 6
// Output: 15
// Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange, and the number of bottles drunk.

// Example 2:

// Input: numBottles = 10, numExchange = 3
// Output: 13
// Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange, and the number of bottles drunk.
 
// Constraints:

// 1 <= numBottles <= 100 
// 1 <= numExchange <= 100