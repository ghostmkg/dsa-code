import java.util.*;

public class LeadersInArr {

    public static void main(String[] args) {
        int[] arr = { 16, 17, 4, 3, 5, 2 };
        int n = arr.length;
        List<Integer> leaders = new ArrayList<>();

        int maxFromRight = arr[n - 1];
        leaders.add(maxFromRight);

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxFromRight) {
                maxFromRight = arr[i];
                leaders.add(maxFromRight);
            }
        }

        // Reverse to get leaders in correct order
        Collections.reverse(leaders);
        System.out.println(leaders);
    }
}
