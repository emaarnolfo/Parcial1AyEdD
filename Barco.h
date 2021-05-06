#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef struct{
    int fila;
    int columna;
} Posicion;

class Barco {
    private:
        Posicion pos[4];
        string tipo;
        int size;
    public:
        void set_pos(int indice, int f, int c);
        void set_tipo(int x);
        void imprimeBarco();
};

void Barco::set_pos(int indice, int f, int c){
    pos[indice].fila = f;
    pos[indice].columna = c;
}

void Barco::set_tipo(int x){
    if(x==0){
        tipo = "submarino";
        size = x+1;
    }
    if(x==1){
        tipo = "cañonera";
        size = x+1;
    }
    if(x==2){
        tipo = "crucero";
        size = x+1;
    }
    if(x==3){
        tipo = "destructor";
        size = x+1;
    }
}

void Barco::imprimeBarco(){
    cout <<"El " <<tipo <<" esta en la posicion:";
    for(int i = 0; i < size; i++){
        cout<<" <" <<pos[i].fila <<"-" <<pos[i].columna <<"> ";
    }
    cout <<endl;

}


