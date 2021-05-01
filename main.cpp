#include <cstdlib>
#include <iostream>
//#include <sstream>
#include "Barco.h"
#include "ColaEstatica.h"

static int filasTablero = 10;
static int colTablero = 10;
int barcosHundidos = 0;

using namespace std;

void disparo(Pila* p);

int main(int argc, char *arg[])
{
    cout<<"Inicio de programa" <<endl;
    
    bool tablero[10][10];
    int fila, columna;
    Barco barcos[10];
    ColaDePilas* posiciones = new ColaDePilas(); 
    //Pila* sigDisparo = new Pila();

    /*
    for(int i=0; i<10; i++){
        for(int j=0; i<10; j++){
            Pila* nuevo = new Pila();
            //nuevo->apilar(i, j); 
            posiciones->encolar(nuevo);
        }
    }
    */

    //cout<<"Cargue los datos correctamente" <<endl;
    

    //posiciones->imprimir();

    cout << "Llegue al final";
   
    /*
    while(barcosHundidos < 10)
    {
    sigDisparo->apilar(fila, columna);             
    posiciones->desencolar();
   
    disparo(sigDisparo);
    }
 */

    
    //cout <<"Llegue al final" <<endl;
    //system("PAUSE");
    //return EXIT_SUCCESS;

}
/*
void disparo (Pila* p){
    char estado;
    cout << "Disparo en fila: " << p->tope()->get_fila() <<" y columna: " <<p->tope()->get_col() <<endl;
    cout << "Indique estado:" <<endl;
    cin  >> estado;
    switch(estado){
        case 'a':
        p->desapilar();
        break;
        case 'v':
        break;
        case 'h':
        barcosHundidos++;
        break;
        default: cout << "Ingreso una letra incorrecta";
    }
}*/

void disparo (Pila* p){
    char estado;

    cout << "Disparo en fila: " << p->tope()->get_fila() <<" y columna: " <<p->tope()->get_col() <<endl;
    cout << "Indique estado:" <<endl;
    cin  >> estado;
    switch(estado){
        case 'a':
        p->desapilar();
        break;

        case 'v':

        break;

        case 'h':
        barcosHundidos++;

        break;
        default: cout << "Ingreso una letra incorrecta";
    }

}