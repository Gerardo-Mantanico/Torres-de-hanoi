#include <iostream>
#include "../clases/PintarTorre.h"
#include "../clases/Pila.h"
#include "../clases/Disco.h"
#include <stack>
using namespace  std;

PintarTorre::PintarTorre() {}
 //metodo para generar espacios
 void espacio(int size){
     for (int i = 0; i <size; ++i) {
         cout<<" ";
     }
 }

 //metodo para imprimir el encabezado de los discos
 void header(Disco disco){
     int espacios=(15-disco.size)/2;
     for (int i = 0; i <espacios; ++i) {
         printf(" ");
     }
     printf("%c", 201);
     for(int i=0; i<disco.size;i++){
         printf("%c", 205); // ═
     }
     printf("%c", 187);
     for (int i = 0; i <espacios; ++i) {
         printf(" ");
     }
 }
//metodo para imprimir el fooder de los discos
 void fooder(Disco disco){
     int espacios=(15-disco.size)/2;
     for (int i = 0; i <espacios; ++i) {
         printf(" ");
     }
     printf("%c", 200);
     for(int i=0; i<disco.size;i++){
         printf("%c", 205); // ═
     }
     printf("%c", 188);
     for (int i = 0; i <espacios; ++i) {
         printf(" ");
     }
}

Pila imprimir(Pila *pila){
    stack<Disco> aux;
    Nodo *tem= pila->discos();
    //insertamos los elementos en la pila
    while (tem !=NULL){
        aux.push(tem->disco);
        tem=tem->siguiente;
    }
    //imprimir en orden inverso
    while (!aux.empty()){

    }

}

Disco* cargar_arreglos(Pila *pila) {
    Nodo *aux = pila->discos();
    stack<Disco> temp; // Pila temporal para almacenar los discos
    Disco *torre = new Disco[7]{};
    int cont = 6;
    while (aux != nullptr && cont < 7) {
        temp.push(aux->disco);
        //cout<< " D. " << aux->disco.posicion<<"   Tama;no: "<< aux->disco.size << endl;
        aux = aux->siguiente;
    }
    while (!temp.empty()) {
        torre[cont] = temp.top(); // Asignamos el disco de la cima de la pila temporal al array
        temp.pop(); // Quitamos el disco de la cima de la pila temporal
        cont--;
    }
    return torre;
}

void PintarTorre::pintar_tabla(Pila *pila1, Pila *pila2, Pila *pila3) {
   pila1->imprimir();
   Disco *torre1= cargar_arreglos(pila1);
   Disco *torre2= cargar_arreglos(pila2);
   Disco *torre3= cargar_arreglos(pila3);
    cout<<endl;
    cout<<endl;
    for (int i = 0; i<7; ++i) {
        espacio(10);
        cout<<"D. "<<torre1[i].posicion<<" ";
        header(torre1[i]);  // torre 1
        if(torre1[i].size==0){
            espacio(11);
        }
        else {espacio(10);}
        cout<<"  D. "<<torre2[i].posicion<<" ";
        header(torre2[i]);        //torre 2
        if(torre1[i].size==0){
            espacio(11);
        }
        else {espacio(10);}
        cout<<"  D. "<<torre3[i].posicion<<" ";
        header(torre3[i]);
        espacio(10);
        cout<<endl;
        cout<<"  ";
        espacio(13);
        fooder(torre1[i]);    //torre 1
        if(torre1[i].size==0){
            espacio(18);
        }
        else {espacio(17);}
        fooder(torre2[i]);          //torre 2
        if(torre1[i].size==0){
            espacio(18);
        }
        else {espacio(17);}
        fooder(torre3[i]);           //torre
        cout<<endl;
    }
    cout<<endl<<endl;
    for (int i = 0; i <60 ; ++i) {
        if(i==12){cout<<"   Torre 1   ";}
        else if(i==28){cout<<"   Torre 2   ";}
        else if(i==41){cout<<"   Torre 3   ";}
        else{   printf("%c", 205);}
    }
    cout<<endl;
}

