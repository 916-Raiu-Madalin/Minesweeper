#pragma once
#include <iostream>
#include <vector>
class Observer{
public:
    virtual void update()=0;
    virtual ~Observer() =default;

};

class Subject{
private:
    std::vector<Observer*>observers;
public:
    void addObserver(Observer* observer){

        this->observers.push_back(observer);

    };
    void notify(){
        for(auto observer:this->observers)
            observer->update();
    }
};

