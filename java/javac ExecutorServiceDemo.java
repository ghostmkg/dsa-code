// 9. ExecutorService thread pool executing multiple tasks: print numbers and factorial calculation
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class PrintNumbersTask implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " prints: " + i);
            try { Thread.sleep(100); } catch (InterruptedException e) {}
        }
    }
}

class FactorialTask implements Runnable {
    private int number;

    public FactorialTask(int number) {
        this.number = number;
    }

    private long factorial(int n) {
        if (n <= 1) return 1;
        else return n * factorial(n - 1);
    }

    public void run() {
        long fact = factorial(number);
        System.out.println(Thread.currentThread().getName() + " factorial of " + number + " is " + fact);
    }
}

class ExecutorServiceDemo {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(3);

        executor.execute(new PrintNumbersTask());
        executor.execute(new FactorialTask(5));
        executor.execute(new PrintNumbersTask());

        executor.shutdown();
    }
}
