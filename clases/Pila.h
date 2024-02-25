#include "Nodo.h"
#include <vector>
#ifndef TORRE_HANOI_PILA_H
#define TORRE_HANOI_PILA_H


class Pila {
private:
    Nodo nodo;
    Nodo * raiz;
public:
    int size_disco[];
    Pila(); //contructor
    ~Pila();    //destrucor
    void push(Disco disco);
    Disco pop();
    Nodo* discos();
    void imprimir();
    int ultimo_valor();
};


#endif //TORRE_HANOI_PILA_H
