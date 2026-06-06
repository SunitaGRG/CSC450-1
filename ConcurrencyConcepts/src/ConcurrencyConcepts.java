import java.util.concurrent.atomic.AtomicBoolean;
/*
 * CSC450 - Portfolio Project (Part 2)
 * Program: Concurrent Thread Counters
 *
 * Thread 1: counts 0 → 20
 * Thread 2: waits for Thread 1, then counts 20 → 0
 */

public class ConcurrencyConcepts {

    // Shared atomic flag ensures safe cross-thread visibility
    private static final AtomicBoolean upDone = new AtomicBoolean(false);

    // Thread 1: Count up
    public static void countUp() {
        for (int i = 0; i <= 20; i++) {
            System.out.println("Thread 1 Count Up: " + i);
            sleepShort(); // helps reduce output flooding
        }
        upDone.set(true);
    }

    // Thread 2: Wait + Count down
    public static void countDown() {

        // Reduced CPU waste compared to pure busy spin
        while (!upDone.get()) {
            sleepShort();
        }

        for (int i = 20; i >= 0; i--) {
            System.out.println("Thread 2 Count Down: " + i);
            sleepShort();
        }
    }

    // Small controlled pause to reduce CPU usage in loops
    private static void sleepShort() {
        try {
            Thread.sleep(10); // lightweight delay
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public static void main(String[] args) throws InterruptedException {

        System.out.println("=== CSC450 Portfolio Project Part 2 ===");
        System.out.println("Concurrent Thread Counters Java)");
        System.out.println();

        Thread t1 = new Thread(ConcurrencyConcepts::countUp);
        Thread t2 = new Thread(ConcurrencyConcepts::countDown);

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println();
        System.out.println("Program Complete.");
    }
}
