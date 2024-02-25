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
                if(pila1->discos()->disco.size>disco.size ){
                    pila1->push(disco);
                }
                else {
                    cout<<"No se puede realizar ese movimento"<<endl;
                }

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

int  size_disco( int torre ){
    if(torre==1){return pila1->ultimo_valor();}
    else if(torre==2){return pila2->ultimo_valor();}
    else if(torre==3){return pila3->ultimo_valor();}
}

Disco  pop( int torre){
    switch (torre) {
        case 1:
                return pila1->pop();

        case 2:
            return pila2->pop();
            break;
        case 3:
            return pila3->pop();
            break;
        default:
            cout << "Opción no válida" << std::endl;
            break;
    }
}


void condiciones_juego(){
    cout <<"Bienvenido al juego de las Torres de Hanoi" << endl;
    int no_disco;
    int no_torre;
    while (caracter!='S'){
        cout<<"Ingrese  el numero de Torre:  ";
        cin>>no_disco;
        while (no_disco <1 || no_disco > 8) {
            cout << "Numero de disco fuera de rango. Insertar un  numero de disco (1-7): ";
            cin >> no_disco;
        }
        cout <<endl<<"Ingrese el numero de la torre:  ";
        cin >> no_torre;
        while (no_torre <1 || no_disco> 4) {
            cout <<"Numero fuera de rango. Insertar un número de torre (1-3): ";
            cin >> no_torre;
        }
        push(no_torre, pop(no_disco));

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