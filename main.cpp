#include "parameters.h"
#include "fieldio.h"
int main () {
    parameters para; 
    para.readPara("parameters.py");
    para.printAll();
    //fieldio_list file;
    // t_io * tmp = new t_io();
    // file.insertNode(tmp);


}

