
Composition -> making use of many object(compound object)

-> This design pattern is a mechanism for treating individual object(called as leaf/scalar) and composition of object in a same/uniform manner.
-> Object which is individual and object which is composition of various objects HAVE THE SAME API.
-> This is achieved by ensuring that both individual and composite objects share the same interface.

eg - 
A great analogy is a computer's file system. A file is a leaf object. A folder is a composite object because it can contain both files and other folders. You can perform an operation like calculateSize() on a single file or an entire folder. The client code doesn't need to differentiate; it treats both uniformly.


## Benefits
- Uniformity: Client code is simplified because it can treat individual objects and compositions of objects in the same way.
- Reduces Coupling: It avoids tight coupling between the client and the specific classes that form the object structure.
- Extensibility: It's easy to add new kinds of components (leaves or composites) to the system without changing the existing code that uses them. This adheres to the Open/Closed Principle.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Uniform behaviour is enforced by this interface.
class GraphicalObject {
public:
    virtual ~GraphicalObject() = default;
    // Public APIs
    virtual double getArea() const = 0;
    virtual void draw() const = 0;
    virtual void add(GraphicalObject* obj) {}
};

class Square : public GraphicalObject {
    double length;
public:
    explicit Square(double l) : length(l) {}

    double getArea() const override {
        return length * length;
    }
    void draw() const override {
        std::cout << "Drawing a Square with area " << getArea() << std::endl;
    }
};

class Circle : public GraphicalObject {
    static constexpr double PI = 3.14159;
    double radius;
public:
    explicit Circle(double r) : radius(r) {}

    double getArea() const override {
        return PI * radius * radius;
    }
    void draw() const override {
        std::cout << "Drawing a Circle with area " << getArea() << std::endl;
    }
};

class Group : public GraphicalObject {
    std::string m_name;
    std::vector<GraphicalObject*> objects;
public:
    explicit Group(const std::string& name) : m_name(name) {}

    ~Group() {
        std::cout << "Cleaning up group: " << m_name << std::endl;
        for (auto* obj : objects) {
            delete obj;
        }
    }

    void add(GraphicalObject* obj) override {
        objects.push_back(obj);
    }

    double getArea() const override {
        double area = 0;
        for (const auto* obj : objects) {
            area += obj->getArea();
        }
        return area;
    }

    void draw() const override {
        std::cout << "--- Drawing Group: " << m_name << " (Total Area: " << getArea() << ") ---" << std::endl;
        for (const auto* obj : objects) {
            obj->draw();
        }
        std::cout << "--- End Group: " << m_name << " ---" << std::endl;
    }
};

int main() {
    auto* circle1 = new Circle(10);
    auto* square1 = new Square(5);

    auto* main_group = new Group("Main Drawing");

    main_group->add(circle1);
    main_group->add(square1);

    auto* sub_group = new Group("Sub-Group");
    sub_group->add(new Circle(2));
    sub_group->add(new Square(3));
    main_group->add(sub_group);

    main_group->draw();

    delete main_group;

    return 0;
}
```
