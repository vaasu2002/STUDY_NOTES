# Strategy Design Pattern

- When there can be multiple ways/algorithm to perform an action or do somethings.
- We encapsulate the different ways in specific classes. [Thus following SRP].


```cpp
#include <iostream>
#include <vector>
#include <string>

/**
 * Strategy Design Pattern
 * When there can be multiple ways/algorithm to perform an action or do somethings.
 * We encapsulate the different ways in specific classes. [Thus following SRP]
 * Morning face routine - Facewash > Vit C serum > Face cream > Sun screen

Night face routine - Facewash > Retinol > Face cream
*/ 

class File;

class ICompressionStrategy{
    public:
    virtual ~ICompressionStrategy() {}
    virtual void compress(File file) = 0;
};

class ZipCompressionStrategy : public ICompressionStrategy{
    public:
    void compress(File file) override {
        // 
    }
};

class HuffmanCompressionStrategy : public ICompressionStrategy{
    public:
    void compress(File file) override {
        // 
    }
};

class RarCompressionStrategy : public ICompressionStrategy{
    public:
    void compress(File file) override {
        // 
    }
};

class Storage{
    ICompressionStrategy* compressionStrategy;
    public:
    void save(File file){
        // while saving the file we might need to compress it
        // adding compression logic
        File compressed = compressionStrategy->compress(file);
    }
};
```
