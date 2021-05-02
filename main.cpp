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
            apilarVecinos(p);
            
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

void apilarVecinos(Pila* p){
    int fila, columna;
    fila = p->tope()->get_fila();
    columna = p->tope()->get_col();

    apilarNvoDisparo(p, fila-1, columna);           //Apilo la posicion de arriba
    apilarNvoDisparo(p, fila+1, columna);           //Apilo la posicion de abajo
    apilarNvoDisparo(p, fila, columna-1);           //Apilo la posicion de izquierda
    apilarNvoDisparo(p, fila, columna+1);           //Apilo la posicion de derecha


    //if(fila>0 && fila<9 && columna>0 && columna<9){
    //    apilarArriba(p, fila-1, columna);
    //    apilarAbajo(p, fila+1, columna);
    //    apilarIzquierda(p, fila, columna-1);
    //    apilarDerecha(p, fila, columna+1);
    //}


}

void apilarNvoDisparo(Pila* p, int fil, int col){
    if(fil<=9 && fil>=0 && col>=0 && col<=9){        // Compruebo que la posicion a apilar esta dentro del tablero
        p->apilar(fil, col);                         // Apilo la nueva posicion
        tablero[fil][col] = true;                    // Marco la posicion del disparo en el tablero para no repetirla
    }
}