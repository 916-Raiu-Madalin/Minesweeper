#pragma once

#include <string>

class Player{
private:
    std::string name;
public:
    Player(std::string &n):name{n}{}

    std::string get_name()const{return name;}

};