# Command Design Pattern

 - Reduce coupling between classes that call one another.
 - Rather than one class calling method of of another class according to the event directly.
 - We can reduce this coupling by expressing different events that occur as their own classes.

#### Bad Code
```cpp
#include <iostream>
#include <vector>

class Canvas{
    std::vector<Object*> objectList;
    public:
    void add(Object* obj){
        objectList.push_back(obj);
    }
    void clearAll(){
        for(auto obj:objectList){
            delete obj;
        }
        objectList.clear();
    }
};

/**
 * Button child contains UI and also bussiness logic [SRP violation]
    * Button knows the business details. 
 * There is hard dependencies between Button and Canvas
    * Any changes in canvas forces button code changesa
 * Hard to add undo/redo, macros, queues
 * Low testability & reuse
*/
class Button{
    public:
    virtual ~Button() {};
    virtual void click() = 0;
};

class AddCircleButton:public Button{
    Canvas* canvas;
    public:
    AddCircleButton(Canvas* canvas):canvas(canvas){}
    void click() override{
        canvas.add(Circle);
    }
};

class AddTriangleButton:public Button{
    Canvas* canvas;
    public:
    AddCircleButton(Canvas* canvas):canvas(canvas){}
    void click() override{
        canvas.add(Circle);
    }
};

class ClearButton:public Button{
    Canvas* canvas;
    public:
    AddCircleButton(Canvas* canvas):canvas(canvas){}
    void click() override{
        canvas.clearAll();
    }
};
```
