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


class ICommand{
    public:
    virtual ~ICommand() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

class AddShapeCommand:public ICommand{
    Object* object;
    Canvas* canvas;
    public:
    AddShapeCommand(Canvas* canvas,Object* object):object(object),canvas(canvas);
    void execute() override{
        
    }
    void undo() override{
        
    }
    void redo() override{
        
    }
};
class ClearObjectCommand:public ICommand{
    Canvas* canvas;
    public:
    ClearObjectCommand(Canvas* canvas):canvas(canvas);
    void execute() override{
        
    }
    void undo() override{
        
    }
    void redo() override{
        
    }
};

class Button{
    ICommand* command;
    public:
    Button(ICommand* command):command(command){}
    virtual ~Button() {};
    void click(){
        command->execute();
    }
};

int main(){
    return 0;
}
