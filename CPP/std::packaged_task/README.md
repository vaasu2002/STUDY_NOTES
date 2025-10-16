Wrapping the callable in std::packaged_task

std::packaged_task wraps a callable, allows it to be run later, by calling it like a function and automatically stores its return value (or exception) in a std::future.
```cpp
std::packaged_task<int()> task([] { return 2 + 3; });
std::future<int> fut = task.get_future();
task()
fut.get()
```
