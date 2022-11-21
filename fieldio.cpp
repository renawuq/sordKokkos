#ifndef FIELDIO_CPP
#define FIELDIO_CPP
#include "fieldio.h"

Fieldio::Fieldio() {
    head = nullptr;
    // tail = nullptr;
}
Node* Fieldio::createNode(tIo* item){
    Node*n = new Node();
    n->data = item;
    n->next = nullptr;
    return n;
}

Node* Fieldio::createNode(std::string mode, int nc, std::string tfunc, int period, 
    float x1[3], float x2[3], int nb, float ii[4][3], std::string filename, int val, std::string field){
        tIo* nnn;
        tIo n; 
        // std::cout << "live here5" << "\n";
        n.mode = mode;
        n.nc = nc;
        n.tfunc = tfunc;
        n.period = period;
        // std::cout << "live here6" << "\n";

        for (int i = 0; i < 3; i++)
            n.x1[i] = x1[i];   
        for (int i = 0; i < 3; i++)
            n.x2[i] = x2[i];   
        n.nb = nb;
        for (int i = 0 ; i < 4 ; i++)
        {
            for(int j = 0; j < 3; j++)
                n.ii[i][j] = ii[i][j];
        }
        n.filename = filename;
        n.val = val;
        n.field = field;
        // std::cout << "live here4" << "\n";
        nnn = &n; 
        Node* node = createNode(nnn); 
        return node; 
}
void Fieldio::insertNode(std::string mode, int nc, std::string tfunc, int period, 
    float x1[3], float x2[3], int nb, float ii[4][3], std::string filename, int val, std::string field){
    std::cout << "live here1" << "\n";
    Node* item = new Node();
    // std::cout << "live here2" << "\n";

    item = createNode(mode, nc, tfunc, period, x1, x2, nb, ii, filename, val, field);
    // std::cout << "live here3" << "\n";

    item -> next = head;
    head = item;
}
Node* Fieldio::getHead()
{
    return head;
}

std::ostream& operator << (std::ostream& out, const Fieldio& list)
{
    for(Node* walk = list.head; walk != nullptr; walk = walk-> next)
    {
        struct tIo t;
        tIo* tio  = &t;
        tio = walk->data; 
        return out << "Mode: " << tio->mode << "\n"
              << "nc: " << tio->nc << "\n"
              << "tfunc: " << tio->tfunc << "\n"
              << "period: " << tio->period << "\n" 
              << "nb: " << tio->nb << "\n"
              << "filename: " << tio->filename << "\n"
              << "val: " << tio->val << "\n" 
              << "field: " << tio->field << "\n";
    }
    return out;
}



#endif