#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Observable;

// Object listening to the events (Subscriber) WISHES TO LISTEN FOR THE EVENT
class Observer {
public:
    virtual ~Observer() {}
    virtual void notify(Observable* observable, const std::string& message) = 0;
};

// Object sending notifcation to (Publisher) HERE THE EVENT IS GENERATED
class Observable {
    std::vector<Observer*> observers;
public:
    virtual ~Observable() {}
    void subscribe(Observer* observer) {
        observers.push_back(observer);
    }

    void unsubscribe(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

protected:
    void notify(const std::string& message) {
        for (auto* observer : observers) {
            observer->notify(this, message);
        }
    }
};

class EmailObserver : public Observer {
public:
    void notify(Observable* observable, const std::string& message) override {
        //
    }
};

class SmsObserver : public Observer {
public:
    void notify(Observable* observable, const std::string& message) override {
        // 
    }
};

class Channel : public Observable {
    std::string name;
    std::vector<std::string> videos;
public:
    Channel(const std::string& name) : name(name) {}
    void addVideo(const std::string& video) {
        videos.push_back(video);
        std::cout << name << " uploaded: " << video << "\n";
        notify("New video on " + name + ": " + video);
    }
};

