#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

typedef struct{
    int fila;
    int columna;
} Posicion;

class Barco {
    private:
        Posicion pos[4];
        string tipo;
    public:
        void get_pos(int indice, int f, int c);
        void get_tipo(int x);
};

void Barco::get_pos(int indice, int f, int c){
    pos[indice].fila = f;
    pos[indice].columna = c;
}

void Barco::get_tipo(int x){
    if(x==1)
        tipo = "submarino";
    if(x==2)
        tipo = "cañoneras";
    if(x==3)
        tipo = "cruceros";
    if(x==4)
        tipo = "destructor";
}


