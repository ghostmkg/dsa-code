// Stack implementation using Array in Java
class Stack {
    private int top;
    private int[] arr;
    private int capacity;

    // Constructor
    public Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Add element to stack
    public void push(int x) {
        if (isFull()) {
            System.out.println("Stack Overflow!");
            return;
        }
        arr[++top] = x;
        System.out.println("Pushed: " + x);
    }

    // Remove element from stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow!");
            return -1;
        }
        return arr[top--];
    }

    // Peek top element
    public int peek() {
        if (!isEmpty())
            return arr[top];
        else {
            System.out.println("Stack is Empty!");
            return -1;
        }
    }

    // Return size
    public int size() {
        return top + 1;
    }

    // Check if empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Check if full
    public boolean isFull() {
        return top == capacity - 1;
    }
}

// Driver code
public class StackMain {
    public static void main(String[] args) {
        Stack stack = new Stack(5);

        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Top element: " + stack.peek());
        System.out.println("Stack size: " + stack.size());

        System.out.println("Popped: " + stack.pop());
        System.out.println("Top element after pop: " + stack.peek());

        while (!stack.isEmpty()) {
            System.out.println("Popped: " + stack.pop());
        }
    }
}
