#include <iostream>
#include <vector>
#include <string>
/**
 * State Design Pattern
 * 
 * It is used when we have a class that can be in several different state and behave differently depending on which state it is in.
 * In such cases using this design pattern we can ENCAPSULATE STATE SPECIFIC BEHAVIOUR INTO SEPERATE CLASS.
 * EASY TO MANAGE STATE TRANSACTION AND EASY TO CHANGE STATE BEHAVIOUR.
 * State interface, each class should contain behaviour and the next step 
*/

enum PurchaseStatus{
    ORDERED,
    IN_TRANSIT,
    DISPATCHED,
    DELIVERED,
    CANCELLED
};

class State{
    public:
    virtual ~State() {}
    virtual std::string getStatus() = 0;
    virtual State* getNextState() = 0;
};

class CanceledState:publc State{
    State* nextState = nullptr;
    public:
    CanceledState(State* nextState):nextState(nextState){}
    std::string getStatus() override {
        return "The purchase order has been canceled"
    }
    State* getNextState() override {
        return nextState;
    }
};

class InTransitState:publc State{
    State* nextState = nullptr;
    public:
    InTransitState(State* nextState):nextState(nextState){}
    std::string getStatus() override {
        return "The purchased order is in transit"
    }
    State* getNextState() override {
        return nextState;
    }
};

class DispatchedState:publc State{
    State* nextState = nullptr;
    public:
    DispatchedState(State* nextState):nextState(nextState){}
    std::string getStatus() override {
        return "The purchased order has been dispatched"
    }
    State* getNextState() override {
        return nextState;
    }
};


class Purchase{
    State* currentState;
    public:
    Purchase(State* currentState):currentState(currentState){}
    std::string getStatus(){
        return currentState->getStatus();
    }
    void goToNextStep(){
        State* nextState = currentState->getNextState();
        if(nextState == nullptr){
            std::cout<<"No more states left"<<std::endl;
            return;
        }
        currentState = nextState;
    }
};




