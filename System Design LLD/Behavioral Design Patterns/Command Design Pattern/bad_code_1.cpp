#include <iostream>
#include <vector>
#include <string>
#include <memory>

/**
 * Command Design Pattern 
 * There is a tight coupling between canvas and Button
 * buttons not only handle the UI things but also are responsible for calling business logic
 * If there is any change in business logic function(canvas  method) we need to change button as well
 * Eg-> if add needs extra parameter or changes name we need to change button as well WHY?
 * 
 * 
 * 
*/
class Canvas{
    std::vector<std::string> objects;
    public:
    void add(const std::string& object){
        std::cout<<"Added: "<<object<<std::endl;
        objects.push_back(object);
    }
    void clearAll(){
        for(const std::string object:objects){
            std::cout<<"Deleted: "<<object<<std::endl;
        }
        objects.clear();
    }
};

class Button{
    std::string name;
    public:
    Button(const std::string& name):name(name){}
    virtual void execute() = 0;
};

class AddRectangleButton:public Button{
    std::shared_ptr<Canvas> canvas;
    public:
    AddRectangleButton(std::shared_ptr<Canvas> canvas):canvas(canvas),Button("Rectangle"){}
    void execute() override {
        canvas->add("Rectangle");
    }
};

class AddCircleButton:public Button{
    std::shared_ptr<Canvas> canvas;
    public:
    AddCircleButton(std::shared_ptr<Canvas> canvas):canvas(canvas),Button("Circle"){}
    void execute() override {
        canvas->add("Circle");
    }
};

class CleanCanvasButton:public Button{
    std::shared_ptr<Canvas> canvas;
    public:
    CleanCanvasButton(std::shared_ptr<Canvas> canvas):canvas(canvas),Button("Clean Canvas"){}
    void execute() override {
        canvas->clearAll();
    }
};

int main(){
    std::shared_ptr<Canvas> canvas = std::make_shared<Canvas>();
    AddRectangleButton addRectangleButton(canvas);
    AddCircleButton addCircleButton(canvas);
    CleanCanvasButton cleanCanvasButton(canvas);
    addRectangleButton.execute();
    addCircleButton.execute();
    cleanCanvasButton.execute();
    return 0;
}
