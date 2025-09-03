#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
/**
 * Observer Design Pattern
 * When one class wants to become aware about event happing in another class
 * Observer/Subscriber -> Intrested in listening to events.
 * Observable/Publisher -> Generates the event.
**/ 


class Observable;

class Observer{
    public:
    virtual void notify(Observable* source, const std::string& message) = 0;
};

class Observable{
    std::string name;
    std::vector<std::unique_ptr<Observer>> observers;
    public:
    Observable(const std::string& name):name(name){}
    void subcribe(std::unique_ptr<Observer> observer){
        observers.push_back(std::move(observer));
    }
    void unsubcribe(std::unique_ptr<Observer> observer){
        // todo: impl to be done
    }
    std::string getName(){return name;}
    protected:
    void notify(const std::string& message){
        for (auto& observer : observers) {
            observer->notify(this, message);
        }
    }
};

class User : public Observable{
    std::vector<std::string> tweets;
    public:
    User(const std::string& name):Observable(name){}
    void createTweet(const std::string& tweet){
        tweets.push_back(tweet);
        notify(tweet);
    }
};

class EmailObserver:public Observer{
    std::string emailId;
    public:
    EmailObserver(const std::string& emailId):emailId(emailId){}
    void notify(Observable* source, const std::string& tweet) override {
        std::cout<<"[Email]: "<<source->getName()<<" added a tweet: "<<tweet<<std::endl;
    }
    std::string getEmailId(){return emailId;}
};

int main(){
    auto user= std::make_unique<User>("Vaasu Bisht");
    std::unique_ptr<Observer> emailSubscriber1 = std::make_unique<EmailObserver>("test@gmail.com");
    user->subcribe(std::move(emailSubscriber1));
    user->createTweet("This is my new tweet!!");
    return 0;
}
