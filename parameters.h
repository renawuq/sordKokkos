#ifndef PARAMETER_H
#define PARAMETER_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include "fieldio.h"
class parameters{
private:
    Fieldio fiel;  
    std::string mode, filename, field; 
    int nc, nb;
    std::string tfunc;
    float val, period; 
    float x1[3];
    float x2[3];
    float ii[4][3];
    

    std::ifstream infile;
    std::map<int, std::string> nodelist; 
    std::map<int, std::string> celllist; 

    int nt, oplevel, ppml, npml, nsource, dip, rake, tpnz, tpsubdt, faultnormal, faultopening,
        itstats, itio, itcheck, itstop, debug, mpin, mpout; 
    int pos =0; 
    int posEnd=0; 
    int track = 0; 
    std::string source, timefunction, ivols, eplasticity, plmodel, tp_method, tp_vw,
                friction, pcdep;
    float tm0, dt, gridnoise, rho1, rho2, vp1, vp2, vs1, vs2, gam1, gam2, vdamp, vpml,
            strike, m0, tv, pleta, vrup, rcrit, trelax, rrelax, tslope, rnucl, tmnucl, delts,
            svtol;

    int nn[3]; 
    int np3[3];
    int ihypo[3];
    int n1expand[3];
    int n2expand[3]; 
    int bc1[3];
    int bc2[3];
    float dx[3]; 
    float source1[3];
    float source2[3];
    float slipvector[3];
    float hourglass[2];
    float affine[3][3]; 
    std::string line;
    std::vector<std::string> firstWord;
    std::string temp; 
    std::string tmp =""; 

public:
    parameters();
    void readPara(std::string filename); 
    void assignOneValue(std::string line, float &num);
    void assignOneValue(std::string line, int &num);
    void assignOneArray(std::string line, int num[], int size);
    void assignOneArray(std::string line, float num[], int size);
    void assignStringValue(std::string line, std::string &tool);
    void assignDoubleArray(std::string line, float num[3][3]);
    void assignDoubleArray2(std::string line, float num[4][3]);
    void readFieldio(std::string line);
    void printAll();
};

#include "parameters.cpp"
#endif // PARAMETER_H

