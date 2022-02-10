#pragma once

#include <vector>
#include "Domain.h"

using namespace std;
class Repository{
private:
    std::vector<Player> elements;
    std::string filename;
    int sizes;
    int bombs;
    int **matrix;
    int **matrixRM;

public:
    Repository(const std::string &file);
    ~Repository();

    void add(Player & p);

    void readFromFile(std::string& file);

    std::vector<Player> data(){return elements;}
    int size() const {return sizes;}
    int bomb(){return bombs;}
    int ** matrixBombs() const {return matrix;}
    int** matrixRevealedMarked(){return matrixRM;};

    int bombsPoz(int row, int col)const{return matrix[row][col];}
    int RMPoz(int row, int col)const{return matrixRM[row][col];}
    void addRM(int row,int cool,int el)const{ matrixRM[row][cool]=el;}
};