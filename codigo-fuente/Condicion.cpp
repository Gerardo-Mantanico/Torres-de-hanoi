#include "../clases/Condiciones.h"
#include "../clases/Pila.h"
#include "../clases/PintarTorre.h"
#include <algorithm> // Para std::shuffle
#include <random>
#include <cstdlib>
#include <iostream>
using namespace std;
Condiciones::Condiciones() {}
char caracter;
Pila *pila1;
Pila *pila2;
Pila *pila3;
PintarTorre *pintar;

void generar_discos_aleatorio(Pila *pila) {
        int sizes[]= {3, 5, 7, 9, 11, 13, 15};
        int num_discos = sizeof(sizes) / sizeof(int);
        vector<int> discos(sizes, sizes + num_discos);
        random_device rd;
        mt19937 gen(rd());
        shuffle(discos.begin(), discos.end(), gen);
        for (int i = 0; i < num_discos; ++i) {
            Disco disc;
            disc.size=discos[i];
            disc.posicion=i+1;
            pila->push(disc);

        }
}


void push( int torre , Disco disco){
    switch (torre) {
        case 1:
                    pila1->push(disco);
            break;
        case 2:
                pila2->push(disco);
            break;
        case 3:
                pila3->push(disco);
            break;
        default:
            cout << "Opción no válida" << std::endl;
            break;
    }
}

Disco  size_disco( int torre ){
    if(torre==1){return pila1->ultimo_valor();}
    else if(torre==2){return pila2->ultimo_valor();}
    else if(torre==3){return pila3->ultimo_valor();}
}

Disco  pop( int torre, int size){
    switch (torre) {
        case 1:
            return pila1->pop(size);
            break;
        case 2:
            return pila2->pop(size);
            break;
        case 3:
            return pila3->pop(size);
            break;
        default:
            cout << "Opción no válida" << std::endl;
            break;
    }
}


void condiciones_juego(){
    cout <<"Bienvenido al juego de las Torres de Hanoi" << endl;
    int torre1;
    int torre2;
    while (caracter!='S'){
        cout<<"Ingrese  el numero de la torre acutal :  ";
        cin>>torre1;
        while (torre1 <1 || torre1 > 8) {
            cout << "Numero de disco fuera de rango. Insertar un  numero de disco (1-7): ";
            cin >> torre1;
        }
        cout<<"Ingrese el numero de la torre siguiente :  ";
        cin >> torre2;
        while (torre2 <1 || torre2> 4) {
            cout <<"Numero fuera de rango. Insertar un número de torre (1-3): ";
            cin >> torre2;
        }
        Disco disco_final= size_disco(torre1);
        Disco disco_aux=pop(torre1, size_disco(torre2).size);
        if(disco_aux.size!=NULL){
            push(torre2,disco_aux);
        }

        else if(disco_aux.size==NULL && disco_final.size!=0){push(torre1,disco_final);}
        pintar->pintar_tabla(pila1 , pila2, pila3);
    }

}

void Condiciones::jugar() {
    pila1= new Pila();
    pila2= new Pila();
    pila3= new Pila();
    generar_discos_aleatorio(pila1);
    pintar->pintar_tabla(pila1 , pila2, pila3);
    condiciones_juego ();
}