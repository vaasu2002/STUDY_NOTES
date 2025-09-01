#include <iostream>
#include <vector>

/**
 * State Design Pattern
 * 
 * It is used when we have a class that can be in several different state and behave differently depending on which state it is in.
 * In such cases using this design pattern we can ENCAPSULATE STATE SPECIFIC BEHAVIOUR INTO SEPERATE CLASS.
 * EASY TO MANAGE STATE TRANSACTION AND EASY TO CHANGE STATE BEHAVIOUR.
*/

enum PurchaseStatus{
    ORDERED,
    IN_TRANSIT,
    DISPATCHED,
    DELIVERED,
    CANCELLED
}
class Purchase{
    PurchaseStatus currentStatus;
    public:
    std::string getState(){
        if(currentStatus==PurchaseStatus::ORDERED){
            return "Order has been placed";
        }
        else if(currentStatus==PurchaseStatus::IN_TRANSIT){
            return "Order is in transit";
        }
        else if(currentStatus==PurchaseStatus::DISPATCHED){
            return "Order has been dispatched";
        }
        else if(currentStatus==PurchaseStatus::DELIVERED){
            return "Order has been delivered";
        }
        else if(currentStatus==PurchaseStatus::CANCELLED){
            return "Order has been canclled";
        }
    }
};
