//
// Created by raium on 7/7/2021.
//

#include "Controller.h"
#include "Window.h"

Controler::Controler():repo{"../input.txt"} {


    for(const auto& user:repo.data())
    {
        auto* w=new Window{*this,repo,user};
        w->show();
        addObserver(w);

    }
}

void Controler::addReveal(int a,int b)
{
    repo.addRM(a, b,1);
    notify();
}
void Controler::addMark(int a,int b)
{
    repo.addRM(a,b,2);
    notify();
}