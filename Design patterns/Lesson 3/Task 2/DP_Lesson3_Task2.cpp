#include <iostream>
#include <fstream>
#include <vector>

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

class Subject {
public:
    void AddObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void RemoveObserver(Observer* observer) {
        auto it = std::remove(observers_.begin(), observers_.end(), observer);
        observers_.erase(it, observers_.end());
    }

    void warning(const std::string& message) const {
        for (auto observer : observers_) {
            observer->onWarning(message);
        }
    }

    void error(const std::string& message) const {
        for (auto observer : observers_) {
            observer->onError(message);
        }
    }

    void fatalError(const std::string& message) const {
        for (auto observer : observers_) {
            observer->onFatalError(message);
        }
    }

private:
    std::vector<Observer*> observers_;
};



class ObserverW : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class ObserverE : public Observer {
public:
    void onError(const std::string& message) override {
        std::ofstream file("file.txt");
        if (file.is_open())
        {
            file << message << std::endl;
        }
        file.close();
    }
};

class ObserverFE : public Observer {
public:
    void onFatalError(const std::string& message) override {
        std::cout << message << std::endl;
        std::ofstream file("file.txt");
        if (file.is_open())
        {
            file << message << std::endl;
        }
        file.close();
    }
};

int main()
{
    Subject* sub = new Subject;
    ObserverW* ow = new ObserverW;
    ObserverE* oe = new ObserverE;
    ObserverFE* ofe = new ObserverFE;
    sub->AddObserver(ow);
    sub->AddObserver(oe);
    sub->AddObserver(ofe);
    sub->warning("Warning");
    sub->error("Error");
    sub->fatalError("FatalError");
    return 0;
}