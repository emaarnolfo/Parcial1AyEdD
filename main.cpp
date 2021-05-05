#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Barco.h"
#include "ColaEstatica.h"

static int filasTablero = 10;
static int colTablero = 10;
int barcosHundidos;
bool tablero[10][10];
Barco barcos[10];

using namespace std;

void primerDisparo(Pila* p);
void apilarVecinos(Pila* p);
void apilarNvoDisparo(Pila* p, int fil, int col);
void segundoDisparo(Pila* p, int fil, int col);
void tercerDisparo(Pila* p, int fil, int col);
void cuartoDisparo(Pila* p, int fil, int col);

int main(int argc, char *arg[])
{
    //cout<<"Inicio de programa" <<endl;
    int fila, columna;
    int disp_realizados = 0;
    barcosHundidos = 0;
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

    //posiciones->imprimir();

   
    
    while(barcosHundidos<10 || !(posiciones->colavacia()))
    {
        int fil = posiciones->tope()->tope()->get_fila();           //Extraigo la fila de la posicion proxima a disparar
        int col = posiciones->tope()->tope()->get_col();            //Extraigo la columna de la posicion proxima a disparar
        if(!tablero[fil][col]){                                     //Pregunto si ya se realizo algun disparo en esa posicion
            disp_realizados++;
            sigDisparo = posiciones->tope();             
            posiciones->desencolar();
            primerDisparo(sigDisparo);
        }    
    }

    cout << "Las posiciones de los barcos son las siguientes: " <<endl;
    for(int i=0; i < barcosHundidos; i++){
        barcos[i].imprimeBarco();
    }
    
    cout <<"Llegue al final" <<endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}

void primerDisparo (Pila* p){
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
            tablero[fila][columna] = true;
            barcos[barcosHundidos].set_pos(1, fila, columna);

            apilarVecinos(p);
            segundoDisparo(p, fila, columna);

        break;

        case 'h':
            //p->desapilar();
            tablero[fila][columna] = true;
            barcos[barcosHundidos].set_pos(1, fila, columna);
            barcos[barcosHundidos].set_tipo(1);
            barcosHundidos++;
            cout << "Submarino hundido" <<endl;
        break;

        default: 
            cout << "Ingreso una letra incorrecta, digite nuevamente" <<endl;
            primerDisparo(p);
    }

}

void segundoDisparo(Pila* p, int fil1, int col1){               //fil y col de la posicion del disparo anterior
    
    int fila2 = p->tope()->get_fila();                          //Fila donde voy a realizar el segundo disparo consecutivo
    int columna2 = p->tope()->get_col();                        //Columna donde voy a realizar el segundo disparo consecutivo
    char estado;

    cout << "Disparo en fila: " << fila2 <<" y columna: " <<columna2 <<endl;        //pregunto el estado de la fila y columna del segundo disparo
    cout << "Indique estado:";
    cin  >> estado;

    switch(estado){
        case 'a':
            tablero[fila2][columna2] = true;
            p->desapilar();
            segundoDisparo(p, fil1, col1);                                    //Llamo nuevamente a segundo disparo con la fila y columna del disparo anterior
        break;

        case 'v':
            tablero[fila2][columna2] = true;
            barcos[barcosHundidos].set_pos(2, fila2, columna2);
            
            if(fila2<fil1){                                                  //El disparo averiado fue en la posicion de ARRIBA con respecto al disparo anterior
                apilarNvoDisparo(p, fila2+2, columna2);                     //Apilo la posicion de abajo primero por si debo cambiar de direccion
                apilarNvoDisparo(p, fila2-1, columna2);                     //Apilo la posicion de arriba
            }
            if(fila2>fil1){                                                  //El disparo averiado fue en la posicion de ABAJO con respecto al disparo anterior
                apilarNvoDisparo(p, fila2-2, columna2);
                apilarNvoDisparo(p, fila2+1, columna2);
            }
            if(columna2<col1){                                               //El disparo averiado fue en la posicion de la IZQUIERDA con respecto al disparo anterior
                apilarNvoDisparo(p, fila2, columna2+2);
                apilarNvoDisparo(p, fila2, columna2-1);
            }
            if(columna2>col1){                                               //El disparo averiado fue en la posicion de la DERECHA con respecto al disparo anterior
                apilarNvoDisparo(p, fila2, columna2-2);
                apilarNvoDisparo(p, fila2, columna2+1);
            }

            tercerDisparo(p, fila2, columna2);
        break;

        case 'h':
            tablero[fila2][columna2] = true;
            barcos[barcosHundidos].set_pos(2, fila2, columna2);
            barcos[barcosHundidos].set_tipo(2);
            barcosHundidos++;
            cout << "Cañonera hundida" <<endl;
        break;

        default: 
            cout << "Ingreso una letra incorrecta, digite nuevamente" <<endl;
            segundoDisparo(p, fil1, col1);
    }
}

void tercerDisparo(Pila* p, int fila2, int columna2){
    int fila3 = p->tope()->get_fila();
    int columna3 = p->tope()->get_col();
    char estado;

    cout << "Disparo en fila: " << fila3 <<" y columna: " <<columna3 <<endl;        //pregunto el estado de la fila y columna del segundo disparo
    cout << "Indique estado:";
    cin  >> estado;

    switch(estado){
        case 'a':
            tablero[fila3][columna3] = true;
            p->desapilar();
            tercerDisparo(p, fila2, columna2);
        break;

        case 'v':
            tablero[fila3][columna3] = true;
            barcos[barcosHundidos].set_pos(3, fila3, columna3);

            if(fila3<fila2)
                apilarNvoDisparo(p, fila3+3, columna3);
                apilarNvoDisparo(p, fila3-1, columna3);
            if(fila3>fila2)
                apilarNvoDisparo(p, fila3-3, columna3);
                apilarNvoDisparo(p, fila3+1, columna3);
            if(columna3>columna2)
                apilarNvoDisparo(p, fila3, columna3-3);            
                apilarNvoDisparo(p, fila3, columna3+1);            
            if(columna3<columna2)
                apilarNvoDisparo(p, fila3, columna3+3);
                apilarNvoDisparo(p, fila3, columna3-1);

        cuartoDisparo(p);
        break;

        case 'h':
            tablero[fila3][columna3] = true;
            barcos[barcosHundidos].set_pos(3, fila3, columna3);
            barcos[barcosHundidos].set_tipo(3);
            barcosHundidos++;
            cout << "Crucero hundido" <<endl;
        break;

        default:
            cout << "Ingreso una letra incorrecta, digite nuevamente" <<endl;
            tercerDisparo(p, fila2, columna2);
    }

}

void cuartoDisparo(Pila* p){
    int fila4 = p->tope()->get_fila();
    int columna4 = p->tope()->get_col();
    char estado;

    cout << "Disparo en fila: " << fila4 <<" y columna: " <<columna4 <<endl;        //pregunto el estado de la fila y columna del segundo disparo
    cout << "Indique estado:";
    cin  >> estado;

    switch(estado){
        case 'a':
            tablero[fila4][columna4] = true;
            p->desapilar();
            cuartoDisparo(p);
        break;

        case 'h':
            tablero[fila4][columna4] = true;
            barcos[barcosHundidos].set_pos(4, fila4, columna4);
            barcos[barcosHundidos].set_tipo(4);
            barcosHundidos++;
            cout << "Destructor hundido" <<endl;
        break;

        default:
            cout << "Ingreso una letra incorrecta, digite nuevamente" <<endl;
            cuartoDisparo(p);

    }
}

void apilarVecinos(Pila* p){
    int fila, columna;
    fila = p->tope()->get_fila();
    columna = p->tope()->get_col();

    apilarNvoDisparo(p, fila-1, columna);           //Apilo la posicion de ARRIBA
    apilarNvoDisparo(p, fila+1, columna);           //Apilo la posicion de ABAJO
    apilarNvoDisparo(p, fila, columna-1);           //Apilo la posicion de IZQUIERDA
    apilarNvoDisparo(p, fila, columna+1);           //Apilo la posicion de DERECHA
}

void apilarNvoDisparo(Pila* p, int fil, int col){
    if(fil<=9 && fil>=0 && col>=0 && col<=9){        // Compruebo que la posicion a apilar esta dentro del tablero
        p->apilar(fil, col);                         // Apilo la nueva posicion
        tablero[fil][col] = true;                    // Marco la posicion del disparo en el tablero para no repetirla
    }
}