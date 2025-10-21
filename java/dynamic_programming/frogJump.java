
// Frog Jump

// A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
// Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
// If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.


import java.util.*;

class frogJump {
    public boolean canCross(int[] stones) {
          int n = stones.length;
        if (n == 2) {
            return stones[1] == 1;
        }
        Map<Integer, Set<Integer>> reachable = new HashMap<>();
        for (int i = 0; i < n; i++) {
            reachable.put(i, new HashSet<>());
        }
        reachable.get(0).add(0); 

        Map<Integer, Integer> stonePositions = new HashMap<>();
        for (int i = 0; i < n; i++) {
            stonePositions.put(stones[i], i);
        }

        for (int i = 0; i < n; i++) {
            for (int lastJump : new HashSet<>(reachable.get(i))) {
                for (int nextJump : new int[]{lastJump - 1, lastJump, lastJump + 1}) {
                    if (nextJump > 0) {
                        int nextPos = stones[i] + nextJump;
                        if (stonePositions.containsKey(nextPos)) {
                            int nextIndex = stonePositions.get(nextPos);
                            reachable.get(nextIndex).add(nextJump);
                        }
                    }
                }
            }
        }

        return !reachable.get(n - 1).isEmpty();
    
    }

    public static void main(String[] args) {
        frogJump solution = new frogJump();
        int[] stones = {0,1,3,5,6,8,12,17};
        System.out.println(solution.canCross(stones)); // Output: true
       
        int[] stones1 = {0,1,2,3,4,8,9,11};
        System.out.println(solution.canCross(stones1)); // Output: true
    }
}