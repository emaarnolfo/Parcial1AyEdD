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
    if(x==1){
        tipo = "submarino";
        size = x;
    }
    if(x==2){
        tipo = "cañonera";
        size = x;
    }
    if(x==3){
        tipo = "crucero";
        size = x;
    }
    if(x==4){
        tipo = "destructor";
        size = x;
    }
}

void Barco::imprimeBarco(){
    cout <<"El " <<tipo <<"Esta en la posicion:";
    for(int i = 0; i < size; i++){
        cout<<" <" <<pos[i].fila <<"-" <<pos[i].columna <<"> ";
    }
    cout <<endl;

}


