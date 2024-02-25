
#include "../clases/Pila.h"
#include "../clases/Disco.h"
#include <iostream>
using namespace std;
//contructor
Pila::Pila() {
    raiz= nullptr;
}

void Pila::push(Disco disco) {
    Nodo *nuevo_nodo;
    nuevo_nodo= new Nodo();
    nuevo_nodo->disco=disco;
    if(raiz==NULL){
      raiz=nuevo_nodo;
      nuevo_nodo->siguiente=NULL;
    }
    else{
        nuevo_nodo->siguiente=raiz;
        raiz=nuevo_nodo;
    }
}
Disco Pila::pop() {
    if(raiz !=NULL){
       Disco disco;
       disco =raiz->disco;
       Nodo *borrador=raiz;
       raiz=raiz->siguiente;
       delete borrador;
       return disco;
    }
}


Nodo* Pila::discos() {
    Nodo *aux=raiz;
    return aux;
}

void Pila::imprimir()
{
    Nodo *reco = raiz;
    cout << "Listado de todos los elementos de la pila:  ";
    while (reco != NULL)
    {
        cout << reco->disco.size << "-";
        reco = reco->siguiente;
    }
}
int Pila::ultimo_valor() {
    return raiz->disco.size;
}