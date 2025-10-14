package StudentManagement;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Student> students = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        System.out.println("=== Student Management System ===");
        while (true) {
            System.out.println("\n1. Add Student");
            System.out.println("2. Show Students");
            System.out.println("3. Exit");
            System.out.print("Enter choice: ");
            int choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter name: ");
                    String name = sc.nextLine();
                    System.out.print("Enter age: ");
                    int age = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter course: ");
                    String course = sc.nextLine();

                    students.add(new Student(name, age, course));
                    System.out.println("✅ Student added successfully!");
                    break;
                case 2:
                    if (students.isEmpty()) {
                        System.out.println("No students found!");
                    } else {
                        System.out.println("\n=== Student List ===");
                        for (Student s : students) {
                            s.displayInfo();
                        }
                    }
                    break;
                case 3:
                    System.out.println("Exiting program...");
                    sc.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice, try again.");
            }
        }
    }
}
