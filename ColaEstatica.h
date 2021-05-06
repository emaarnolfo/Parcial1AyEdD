<<<<<<< HEAD
// Cola Circular con Arreglo.cpp : 
=======

>>>>>>> emanuel
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Listas02.h"

<<<<<<< HEAD
#define MAX 101
=======
#define MAX 101                             //La cola almacena MAX-1 elementos
>>>>>>> emanuel

using namespace std;

class ColaDePilas {
    private:
<<<<<<< HEAD
        Pila* Q[MAX];
=======
        Pila* pilas[MAX];
>>>>>>> emanuel
        int frente, ult;
    public:
        ColaDePilas(void) { frente = 0; ult = MAX - 1; };
        ~ColaDePilas(void);
<<<<<<< HEAD
        Pila* tope() { return Q[frente]; };
=======
        Pila* tope() { return pilas[frente]; };
>>>>>>> emanuel
        bool colavacia() { return frente == (ult + 1) % MAX; };
        bool colallena() { return frente == (ult + 2) % MAX; };
        void encolar(Pila* a);
        void desencolar();
        Pila* ultimo();
        void imprimir();
    };


<<<<<<< HEAD
//-------- Metodos de la Cola de Pilas --------------------
void ColaDePilas::encolar(Pila* a){
    if (!colallena()) {
        //if (ult == MAX - 2) ult = MAX - 1;
        ult = (ult + 1) % MAX;
        Q[ult] = a;
        cout<<"Encole correctamente" <<endl;
=======
//
void ColaDePilas::encolar(Pila* a){
    if (!colallena()) {
        ult = (ult + 1) % MAX;
        pilas[ult] = a;
>>>>>>> emanuel
    }
    else cout << "Cola llena" << endl;
}

void ColaDePilas::desencolar(void){
    if (!colavacia())frente = (frente + 1) % MAX;
    else cout << "Cola vacia" << endl;
}

Pila* ColaDePilas::ultimo(void){
<<<<<<< HEAD
    return Q[ult];
=======
    return pilas[ult];
>>>>>>> emanuel
}

void ColaDePilas::imprimir(){
    if (!colavacia()) {
<<<<<<< HEAD
       for (int i = frente; i != (ult + 1) % MAX; i = (i + 1) % MAX){
            //cout<<"Llamo a impre de pila" <<endl;
            Q[i]->imprimir();
=======
       for (int i=0; i<MAX-1; i++){
            pilas[i]->imprimir();
>>>>>>> emanuel
       }
    }else{
        cout<<"La cola esta vacia" <<endl;
    }
}
