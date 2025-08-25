```cpp
/*
std::jthread is modern, safer and more convenient version of std::thread.
"j" stands for "joining", as it automatically joins upon destruction.
It is an RAII.

Problem 1.
In std::thread, once object id destroyed while the thread it represents in still running, the 
program terminates by calling std::terminate()

Problem 2.
There is not build in cancellation mechanism, we need to create our own using atomic falgs.

std::jthread solves these Problems.
1. Automatic Joining (RAII)
    std::jthread t(method);
    Once 't' goes out of scopce, destructor is AUTOMATICALLY calls t.join();
    The program will wait here for the thread to finish. No crash!
    
2. Cooperative Cancellation


std::stop_source: An object that can request a stop. Each jthread has its own internal stop_source.

std::stop_token: A lightweight object that a thread can check to see if a stop has been requested.

std::stop_callback: A RAII-style callback that is invoked when a stop is requested (useful for advanced cases like waking up a thread from a condition_variable).
*/

#include <iostream>
#include <thread>
#include <chrono>

// The function now takes a stop_token
void counter_task(std::stop_token token) {
    int i = 0;
    while (!token.stop_requested()) { // Check if a stop has been requested
        std::cout << "Counter: " << i++ << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "Stop requested. Cleaning up and exiting task." << std::endl;
}

int main() {
    // Create the jthread. It will automatically pass a stop_token.
    std::jthread t(counter_task);

    std::cout << "Waiting for 3 seconds before stopping the thread..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "Requesting stop..." << std::endl;
    t.request_stop(); // This is the public way to trigger the stop

    // The jthread's destructor will be called here.
    // The destructor's logic is:
    // 1. If not already requested, call request_stop(). (In this case, it was already called).
    // 2. Call join().
    // This ensures the thread finishes cleanly.
}
```
