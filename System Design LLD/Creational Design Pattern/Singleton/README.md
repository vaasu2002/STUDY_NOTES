# Singleton
For some components it only makes sense to have on component in the system. Singleton is a component which is instantiated only once.
## Testing with Singleton using Dependency Injection (C++)

### Problem
- Using `Singleton` directly (`MyClass::getInstance()`) makes code **hard to test**.  
- Business logic is tightly coupled with the global instance.  
- Cannot easily replace it with a mock/fake during testing.

```cpp
class UserService {
public:
    std::string getUser(int id) {
        // ❌ Hard dependency on singleton
        return Database::getInstance().findUser(id);
    }
};

### Solution: Dependency Injection
```cpp
// Interface
struct IDatabase {
    virtual ~IDatabase() = default;
    virtual std::string findUser(int id) = 0;
};

// Singleton implementation
class Database : public IDatabase {
public:
    static Database& getInstance() {
        static Database instance;
        return instance;
    }
    std::string findUser(int id) override { return "User" + std::to_string(id); }
private:
    Database() = default;
};

// Fake for testing
class FakeDatabase : public IDatabase {
public:
    std::string findUser(int id) override { return "FakeUser" + std::to_string(id); }
};

// UserService depends on abstraction
class UserService {
    IDatabase& db;
public:
    UserService(IDatabase& db) : db(db) {}
    std::string getUser(int id) { return db.findUser(id); }
};

```
