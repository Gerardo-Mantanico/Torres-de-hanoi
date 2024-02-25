
#include "../clases/Pila.h"
#include "../clases/Disco.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
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
Disco Pila::pop(int size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (raiz != NULL) {
        Disco disco;
        disco = raiz->disco;
        Nodo *borrador = raiz;
        raiz = raiz->siguiente;
        if (size != 0) {
            if (size > disco.size) {
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
                cout << "tamano " << size << " disco " << disco.size << endl;
                delete borrador;
                return disco;
            } else {
                SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
                cout <<endl<<endl<< "           Error: No se puede realizar el movimiento. Tamaño proporcionado es menor o igual al tamaño del disco en la cima de la pila." << endl;

                delete borrador;
                Disco disc;
                return disc;
            }
        } else {
            SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
            // No se realiza la eliminación del nodo si size es igual a 0
            return disco;
        }
    } else {
        Disco disc;
        return disc;
    }
}


Nodo* Pila::discos() {
    Nodo *aux=raiz;
    return aux;
}

void Pila::imprimir()
{
    Nodo *reco = raiz;
    cout << "Listado de todos los elementos de la pila:  "<<endl;
    while (reco != NULL)
    {
       // cout<< " D. " << reco->disco.posicion<<"   Tama;no: "<< reco->disco.size << endl;
        reco = reco->siguiente;
    }
}
Disco Pila::ultimo_valor() {
    if(raiz==NULL){
        Disco disc;
        return disc;
    }
    else{ return raiz->disco;}

}