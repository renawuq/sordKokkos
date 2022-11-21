#include "fieldio.h"
#include "tIo.h"
#include <algorithm>
#include <vector>
#include <iterator>
// fieldio::fieldio() {
//     io0 = nullptr;
//     tail = nullptr;
// }

tIo* fieldio::createNode(std::string mode, int nc, std::string tfunc, int period, 
    float x1[3], float x2[3], int nb, float ii[4][3], std::string filename, int val, std::string field){
        tIo* n = new tIo;
        n->mode = mode;
        n->nc = nc;
        n->tfunc = tfunc;
        n->period = period;
        for (int i = 0; i < 3; i++)
            n->x1[i] = x1[i];   
        for (int i = 0; i < 3; i++)
            n->x2[i] = x2[i];   
        n->nb = nb;
        for (int i = 0 ; i < 4 ; i++)
        {
            for(int j = 0; j < 3; j++)
                n->ii[i][j] = ii[i][j];
        }
        n->filename = filename;
        n->val = val;
        n->field = field;
        return n; 
    }
// void fieldio_list::insertNode(){
//     t_io * newNode = new t_io();
//     gio->next = newNode;
//     gio = gio->next;
//     gio->next = gio0; 
// }
void fieldio::insertNode(std::string mode, int nc, std::string tfunc, int period, 
    float x1[3], float x2[3], int nb, float ii[4][3], std::string filename, int val, std::string field){
    tIo* item = fieldio::createNode(mode, nc, tfunc, period, x1, x2, nb, ii, filename, val, field);
    item -> next = io0;
    io0 = item;
}
