import java.util.Scanner;

public class AreaCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- Area Calculator ---");
            System.out.println("1. Circle");
            System.out.println("2. Rectangle");
            System.out.println("3. Triangle");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter radius of circle: ");
                    double radius = sc.nextDouble();
                    double circleArea = 3.14159 * radius * radius;
                    System.out.println("Area of Circle = " + circleArea);
                    break;

                case 2:
                    System.out.print("Enter length of rectangle: ");
                    double length = sc.nextDouble();
                    System.out.print("Enter width of rectangle: ");
                    double width = sc.nextDouble();
                    double rectArea = length * width;
                    System.out.println("Area of Rectangle = " + rectArea);
                    break;

                case 3:
                    System.out.print("Enter base of triangle: ");
                    double base = sc.nextDouble();
                    System.out.print("Enter height of triangle: ");
                    double height = sc.nextDouble();
                    double triArea = 0.5 * base * height;
                    System.out.println("Area of Triangle = " + triArea);
                    break;

                case 4:
                    System.out.println("Exiting program. Goodbye!");
                    break;

                default:
                    System.out.println("Invalid choice! Please try again.");
            }

        } while (choice != 4);

        sc.close();
    }
}
