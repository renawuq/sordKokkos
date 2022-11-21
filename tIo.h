#ifndef TIO_H
#define TIO_H
#include <iostream>
struct tIo
{
    std::string mode, tfunc, filename, field;
    int nc, nb;
    float period, val; 
    float x1[3];
    float x2[3];
    float ii[4][3];
    tIo* next;
};
#endif //TLO_H
