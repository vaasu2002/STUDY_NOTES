std::bind creates a callable with no parameters, by "binding" all of its arguments ahead of time.

```cpp
int add(int a, int b) { return a + b; }
auto bound = std::bind(add, 2, 3);
bound();
```
bound is a callable object of type std::function<int()> — it needs no arguments.
