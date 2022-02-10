//
// Created by raium on 7/7/2021.
//

#include <fstream>
#include <iostream>
#include "Repository.h"

Repository::Repository(const std::string &file) :filename{file}{
    readFromFile(filename);
    this-> matrix = (int**)malloc(sizes* sizeof(int*));
    for(int i=0;i<sizes;i++)
        matrix[i]=(int*)malloc(sizes*sizeof(int));

    for(int i=0;i<sizes;i++)
        for(int j=0;j<sizes;j++)
            this->matrix[i][j]=0;
    for(int i=0;i<sizes;i++)
    {
        int v1=rand()%(sizes-1);
        int v2=rand()&(sizes-3);
        this->matrix[v1][v2]=1;

    }

    this-> matrixRM = (int**)malloc(sizes* sizeof(int*));
    for(int i=0;i<sizes;i++)
        matrixRM[i]=(int*)malloc(sizes*sizeof(int));

    for(int i=0;i<sizes;i++)
        for(int j=0;j<sizes;j++)
            this->matrixRM[i][j]=0;





}


Repository::~Repository() {}

void Repository::add(Player &p) {
    elements.push_back(p);

}

void Repository::readFromFile(std::string &file) {

    std::ifstream fin(filename,std::ios::in);
    std::string line;
    elements.clear();

    if(fin.is_open())
    {   getline(fin,line);
        sizes=stoi(line);
        getline(fin,line);
        bombs=stoi(line);
        while(getline(fin,line)){
            Player p{line};
            elements.push_back(p);
        }
        fin.close();
    }
    else
        std::cout<<"help read";
}