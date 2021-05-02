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
void apilarVecinos(Pila* p);
void apilarNvoDisparo(Pila* p, int fil, int col);
void segundoDisparo(Pila* p, int fil, int col);


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
   
    
    while(barcosHundidos < 10)
    {
        int fil = posiciones->tope()->tope()->get_fila();           //Extraigo la fila de la posicion proxima a disparar
        int col = posiciones->tope()->tope()->get_col();            //Extraigo la columna de la posicion proxima a disparar
        if(!tablero[fil][col]){                                     //Pregunto si ya se realizo algun disparo en esa posicion
            sigDisparo = posiciones->tope();             
            posiciones->desencolar();
            disparo(sigDisparo);
        }    
    }
 

    
    cout <<"Llegue al final" <<endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}

void disparo (Pila* p){
    char estado;
    int fila = p->tope()->get_fila();                   //extraigo la fila donde voy a realizar el primer disparo
    int columna = p->tope()->get_col();                 //extraigo la columna donde voy a realizar el primer disparo


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
            apilarVecinos(p);
            segundoDisparo(p, fila, columna);

        break;

        case 'h':
            //p->desapilar();
            tablero[fila][columna] = true;
            barcosHundidos++;
            cout << "Barco hundido" <<endl;
        break;

        default: 
            cout << "Ingreso una letra incorrecta, digite nuevamente" <<endl;
            disparo(p);
    }

}

void apilarVecinos(Pila* p){
    int fila, columna;
    fila = p->tope()->get_fila();
    columna = p->tope()->get_col();

    apilarNvoDisparo(p, fila-1, columna);           //Apilo la posicion de arriba
    apilarNvoDisparo(p, fila+1, columna);           //Apilo la posicion de abajo
    apilarNvoDisparo(p, fila, columna-1);           //Apilo la posicion de izquierda
    apilarNvoDisparo(p, fila, columna+1);           //Apilo la posicion de derecha
}

void apilarNvoDisparo(Pila* p, int fil, int col){
    if(fil<=9 && fil>=0 && col>=0 && col<=9){        // Compruebo que la posicion a apilar esta dentro del tablero
        p->apilar(fil, col);                         // Apilo la nueva posicion
        tablero[fil][col] = true;                    // Marco la posicion del disparo en el tablero para no repetirla
    }
}


void segundoDisparo(Pila* p, int fil, int col){     //fil y col es la posicion del disparo anterior
    
    int fil2 = p->tope()->get_fila();
    int col2 = p->tope()->get_col();
    char estado;

    cout << "Disparo en fila: " << fil2 <<" y columna: " <<col2 <<endl;        //pregunto el estado de la fila y columna del segundo disparo
    cout << "Indique estado:";
    cin  >> estado;

    switch(estado){
        case 'a':
            p->desapilar();
            segundoDisparo(p, fil, col);
        break;

        case 'v':
            
        break;

        case 'h':
            barcosHundidos++;
        break;
    }

}