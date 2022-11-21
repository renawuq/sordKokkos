#ifndef FIELDIO_H
#define FIELDIO_H

#include "tIo.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
// t_io * gio,gio0,gioprev;

class Fieldio{
private:            
    tIo* io0; // head 
    tIo* tail;
    tIo* createNode(std::string mode, int nc, std::string tfunc, int period, 
    float x1[3], float x2[3], int nb, float ii[4][3], std::string filename, int val, std::string field);

public:
    Fieldio();
    void insertNode(std::string mode, int nc, std::string tfunc, int period, 
    float x1[3], float x2[3], int nb, float ii[4][3], std::string filename, int val, std::string field);
    
};

// class fieldio_list{    
//     public:
//         fieldio_list() {}//gio0=NULL;}
//         void insertNode();
//         void deleteNode();
// };

#include "fieldio.cpp"
#endif // FIELDIO_H

