#include <cstdlib>
#include <iostream>
<<<<<<< HEAD
#include <sstream>
#include "Barco.h"
#include "Cola.h"
=======
//#include <sstream>
#include "Barco.h"
#include "ColaEstatica.h"
>>>>>>> emanuel

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
<<<<<<< HEAD
    Cola* posiciones = new Cola(); 
    Pila* sigDisparo = new Pila();

   
    for(int i=0; i<10; i++){
        for(int j=0; i<10; j++){
            Pila* nuevo = new Pila();
            //nuevo->apilar(i, j); 
=======
    ColaDePilas* posiciones = new ColaDePilas(); 
    //Pila* sigDisparo = new Pila();
    //Pila* p1 = new Pila();
    //p1->add(2, 3);
//
    //posiciones->encolar(p1);
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout <<"Iteracion: " <<i <<"-" <<j <<endl;
            Pila* nuevo = new Pila();
            nuevo->apilar(i, j); 
>>>>>>> emanuel
            posiciones->encolar(nuevo);
        }
    }
    
    

    cout<<"Cargue los datos correctamente" <<endl;
    
    cout<<"-----------------IMPRIMO LAS POSICIONES---------" <<endl;
    posiciones->imprimir();

<<<<<<< HEAD
    cout<<"Cargue los datos correctamente" <<endl;
    

    posiciones->imprimir();

=======
>>>>>>> emanuel
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
<<<<<<< HEAD
    system("PAUSE");
    return EXIT_SUCCESS;

}
/*
=======
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

>>>>>>> emanuel
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
