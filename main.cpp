#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Listas02.h"
#include "Barco.h"

static int filasTablero = 10;
static int colTablero = 10;
int barcosHundidos = 0;

using namespace std;

void disparo(Pila* p){}

int main()
{
    int tablero[10][10];
    int fila, columna;
    Barco barcos[10];
    Cola* posiciones = new Cola(); 
    Pila* sigDisparo = new Pila();

    for(int i=0; i<filasTablero; i++){
        for(int j=0; i<colTablero; j++){
            posiciones->add(i,j);
        }
    }

    //cout << posiciones->imprimir("fin");
    while(barcosHundidos < 10)
    {
    sigDisparo->apilar(fila, columna);             
    posiciones->desencolar();
   
    disparo(sigDisparo);
    }

    system("PAUSE");
    return EXIT_SUCCESS;

}

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