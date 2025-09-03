#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stack>
#include <algorithm>

/**
 * Command Design Pattern
 * There are 4 components:
 * 1) Receiver
 * 2) Command
 * 3) Invoker
 * 4) Client
 * 
 * 
 * 
 * 
*/
// Receiver class => Knows what to do
class Canvas {
    std::vector<std::string> objects;
public:
    void add(const std::string& object) {
        std::cout << "Added: " << object << std::endl;
        objects.push_back(object);
    }
    void remove(const std::string& object) {
        auto it = std::find(objects.begin(), objects.end(), object);
        if (it != objects.end()) {
            std::cout << "Deleted: " << object << std::endl;
            objects.erase(it);
        }
    }
    std::vector<std::string> getAll() {
        return objects;
    }
    void clearAll() {
        for (const std::string& object : objects) {
            std::cout << "Deleted: " << object << std::endl;
        }
        objects.clear();
    }
};

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class AddShapeCommand : public Command {
    std::shared_ptr<Canvas> canvas;
    std::string object;
public:
    AddShapeCommand(const std::string& object, std::shared_ptr<Canvas> canvas)
        : object(object), canvas(canvas) {}
    void execute() override {
        canvas->add(object);
    }
    void undo() override {
        canvas->remove(object);
    }
};

class ClearCanvasCommand : public Command {
    std::shared_ptr<Canvas> canvas;
    std::vector<std::string> objectsBackUp;
public:
    ClearCanvasCommand(std::shared_ptr<Canvas> canvas) : canvas(canvas) {}
    void execute() override {
        objectsBackUp = canvas->getAll();
        canvas->clearAll();
    }
    void undo() override {
        for (const std::string& object : objectsBackUp) {
            canvas->add(object);
        }
    }
};

class CommandManager {
    std::stack<std::unique_ptr<Command>> undoStore; // helps us to perform undo operation
    std::stack<std::unique_ptr<Command>> redoStore; // helps us to perform redo operation
public:
    void executeCommand(std::unique_ptr<Command> command) {
        command->execute();
        undoStore.push(std::move(command));
        while (!redoStore.empty()) redoStore.pop(); // clear redo on new command
    }

    void undo() {
        if (undoStore.empty()) {
            std::cout << "Cannot Undo" << std::endl;
            return;
        }
        auto command = std::move(undoStore.top());
        undoStore.pop();
        command->undo();
        redoStore.push(std::move(command));
    }

    void redo() {
        if (redoStore.empty()) {
            std::cout << "Cannot Redo" << std::endl;
            return;
        }
        auto command = std::move(redoStore.top());
        redoStore.pop();
        command->execute();
        undoStore.push(std::move(command));
    }
};

class Button {
    std::string label;
    std::unique_ptr<Command> command;
    CommandManager& manager;
public:
    Button(const std::string& label,
           std::unique_ptr<Command> command,
           CommandManager& manager)
        : label(label), command(std::move(command)), manager(manager) {}

    void press() {
        std::cout << "Button pressed: " << label << std::endl;
        manager.executeCommand(std::move(command));
    }
};

int main() {
    auto canvas = std::make_shared<Canvas>();
    CommandManager manager;

    Button addCircleButton("Add Circle",
        std::make_unique<AddShapeCommand>("Circle", canvas), manager);

    Button addTriangleButton("Add Triangle",
        std::make_unique<AddShapeCommand>("Triangle", canvas), manager);

    Button clearButton("Clear Canvas",
        std::make_unique<ClearCanvasCommand>(canvas), manager);

    addCircleButton.press();
    addTriangleButton.press();
    clearButton.press();

    std::cout << "\n--- Undoing actions ---\n";
    manager.undo();  // undo clear
    manager.undo();  // undo add triangle
    manager.undo();  // undo add circle
    manager.undo();  // nothing left

    std::cout << "\n--- Redoing actions ---\n";
    manager.redo();  // redo add circle
    manager.redo();  // redo add triangle
    manager.redo();  // redo clear
    manager.redo();  // nothing left
}
