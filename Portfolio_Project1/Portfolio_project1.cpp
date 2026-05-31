/*
 * CSC450 - Portfolio Project (Part 1)
 * Concurrent Thread Counters
 *
 * Thread 1 counts up from 0 to 20.
 * Once Thread 1 finishes, Thread 2 counts down from 20 to 0.
 */

#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

// Shared flag - atomic guarantees safe access across threads
atomic<bool> upDone(false);

// Thread 1: Counts up from 0 to 20
void countUp() {
    for (int i = 0; i <= 20; i++) {
        cout << "Thread 1 Count Up: " << i << endl;
    }
    upDone = true;   // Signal completion to Thread 2
}

// Thread 2: Waits for Thread 1, then counts down from 20 to 0
void countDown() {
    // Wait until Thread 1 signals it has finished
    while (!upDone.load()) {
    std::this_thread::yield();
	}

    for (int i = 20; i >= 0; i--) {
        cout << "Thread 2 Count Down: " << i << endl;
    }
}

int main() {
    cout << "=== CSC450 Portfolio Project Part 1 ===" << endl;
    cout << "Concurrent Thread Counters" << endl << endl;

    // Launch both threads concurrently
    thread t1(countUp);
    thread t2(countDown);

    // Wait for both threads to complete
    t1.join();
    t2.join();

    cout << endl << "Program Complete." << endl;
    return 0;
}
