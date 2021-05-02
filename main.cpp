#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Barco.h"
#include "ColaEstatica.h"

static int filasTablero = 10;
static int colTablero = 10;
int barcosHundidos = 0;
bool tablero[10][10];

using namespace std;

void disparo(Pila* p);

int main(int argc, char *arg[])
{
    //cout<<"Inicio de programa" <<endl;

    int fila, columna;
    Barco barcos[10];
    ColaDePilas* posiciones = new ColaDePilas(); 
    Pila* sigDisparo;

    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout <<"Iteracion: " <<i <<"-" <<j <<endl;
            tablero[i][j] = false;
            Pila* nuevo = new Pila();
            nuevo->apilar(i, j); 
            posiciones->encolar(nuevo);
        }
    }
    
    

    cout<<"Cargue los datos correctamente" <<endl;
    
    cout<<"---------IMPRIMO LAS POSICIONES---------" <<endl;

    posiciones->imprimir();

    //cout << "Llegue al final" <<endl;
   
    
    //while(barcosHundidos < 10)
    //{
    sigDisparo = posiciones->tope();             
    posiciones->desencolar();
    disparo(sigDisparo);
    
    //}
 

    
    cout <<"Llegue al final" <<endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}

void disparo (Pila* p){
    char estado;
    int fila = p->tope()->get_fila();                   //extraigo la fila donde voy a disparar
    int columna = p->tope()->get_col();                 //extraigo la columna donde voy a disparar


    cout << "Disparo en fila: " << fila <<" y columna: " <<columna <<endl;        //pregunto el estado de la fila y columna a la que disparo
    cout << "Indique estado:";
    cin  >> estado;

    switch(estado){
        case 'a':
            p->desapilar();
            tablero[fila][columna] = true;
            cout<<"Disparo en agua" <<endl;
        break;

        case 'v':
        break;

        case 'h':
            p->desapilar();
            tablero[fila][columna] = true;
            barcosHundidos++;
        break;

        default: 
            cout << "Ingreso una letra incorrecta, digite nuevamente" <<endl;
            disparo(p);
    }

}