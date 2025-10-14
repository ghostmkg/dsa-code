package ToDoListApp;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Task> tasks = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int choice;

        System.out.println("=== To-Do List App ===");

        do {
            System.out.println("\n1. Add Task");
            System.out.println("2. View Tasks");
            System.out.println("3. Mark Task as Done");
            System.out.println("4. Delete Task");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter task description: ");
                    String desc = sc.nextLine();
                    tasks.add(new Task(desc));
                    System.out.println("✅ Task added!");
                    break;

                case 2:
                    if (tasks.isEmpty()) {
                        System.out.println("No tasks yet!");
                    } else {
                        System.out.println("\n=== Your Tasks ===");
                        for (int i = 0; i < tasks.size(); i++) {
                            System.out.println((i + 1) + ". " + tasks.get(i));
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter task number to mark done: ");
                    int doneIndex = sc.nextInt() - 1;
                    if (doneIndex >= 0 && doneIndex < tasks.size()) {
                        tasks.get(doneIndex).markDone();
                        System.out.println("✅ Task marked as done!");
                    } else {
                        System.out.println("❌ Invalid task number!");
                    }
                    break;

                case 4:
                    System.out.print("Enter task number to delete: ");
                    int delIndex = sc.nextInt() - 1;
                    if (delIndex >= 0 && delIndex < tasks.size()) {
                        tasks.remove(delIndex);
                        System.out.println("🗑️ Task deleted!");
                    } else {
                        System.out.println("❌ Invalid task number!");
                    }
                    break;

                case 5:
                    System.out.println("Exiting To-Do List App. Goodbye!");
                    break;

                default:
                    System.out.println("Invalid choice! Try again.");
            }

        } while (choice != 5);

        sc.close();
    }
}
