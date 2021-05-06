// Cola Circular con Arreglo.cpp : 
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Listas02.h"

#define MAX 101

using namespace std;

class ColaDePilas {
    private:
        Pila* Q[MAX];
        int frente, ult;
    public:
        ColaDePilas(void) { frente = 0; ult = MAX - 1; };
        ~ColaDePilas(void);
        Pila* tope() { return Q[frente]; };
        bool colavacia() { return frente == (ult + 1) % MAX; };
        bool colallena() { return frente == (ult + 2) % MAX; };
        void encolar(Pila* a);
        void desencolar();
        Pila* ultimo();
        void imprimir();
    };


//-------- Metodos de la Cola de Pilas --------------------
void ColaDePilas::encolar(Pila* a){
    if (!colallena()) {
        //if (ult == MAX - 2) ult = MAX - 1;
        ult = (ult + 1) % MAX;
        Q[ult] = a;
      //  cout<<"Encole correctamente" <<endl;
    }
    else cout << "Cola llena" << endl;
}

void ColaDePilas::desencolar(void){
    if (!colavacia())frente = (frente + 1) % MAX;
    else cout << "Cola vacia" << endl;
}

Pila* ColaDePilas::ultimo(void){
    return Q[ult];
}

void ColaDePilas::imprimir(){
    if (!colavacia()) {
       for (int i = frente; i != (ult + 1) % MAX; i = (i + 1) % MAX){
            //cout<<"Llamo a impre de pila" <<endl;
            Q[i]->imprimir();
       }
    }else{
        cout<<"La cola esta vacia" <<endl;
    }
}
