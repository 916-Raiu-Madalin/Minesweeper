#pragma once

#include "Observer.h"
#include "Repository.h"

class Controler: public Subject
{
private:
    Repository repo;
public:
    Controler();

    void addMark(int a, int b);

    void addReveal(int a, int b);
};