import java.util.Arrays;
import java.util.Scanner;

public class MinimumArrowsToBurstBalloons {
    public static int findMinArrows(int[][] points) {
        if (points.length == 0) return 0;

        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

        int arrows = 1;
        int end = points[0][1];

        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of balloons: ");
        int n = scanner.nextInt();
        int[][] balloons = new int[n][2];

        System.out.println("Enter balloon intervals (start end):");
        for (int i = 0; i < n; i++) {
            balloons[i][0] = scanner.nextInt();
            balloons[i][1] = scanner.nextInt();
        }

        int result = findMinArrows(balloons);
        System.out.println("Minimum arrows needed: " + result);
    }
}
