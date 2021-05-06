#include <cstdlib>
#include <iostream>
#include <sstream>
<<<<<<< HEAD
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
    Barco barcos[1];
    ColaDePilas* posiciones = new ColaDePilas(); 
    Pila* sigDisparo;

    //for(int i=0; i<10; i++){
    barcos->impreBarco();
	//}
/*
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout <<"Iteracion: " <<i <<"-" <<j <<endl;
            tablero[i][j] = false;
            Pila* nuevo = new Pila();
            nuevo->apilar(i, j); 
            posiciones->encolar(nuevo);
=======
#include <time.h>
#include "Barco.h"
#include "ColaEstatica.h"

const int filasTablero = 10;
const int colTablero = 10;
int barcosHundidos;
const int n_barcos = 10;
bool tablero[filasTablero][colTablero];
Barco barcos[n_barcos];

using namespace std;

void primerDisparo(Pila* p);
void segundoDisparo(Pila* p, int fil, int col);
void tercerDisparo(Pila* p, int fil, int col);
void cuartoDisparo(Pila* p);
void apilarVecinos(Pila* p);
void apilarNvoDisparo(Pila* p, int fil, int col);
void anularVecinos(Pila* p);
void anularCasillero(int fil, int col);
void cargarDisparosConsecutivos(ColaDePilas* pos);
void cargarDisparosAleatorios(ColaDePilas* pos);

int main(int argc, char *arg[])
{
    int disp_realizados = 0;
    barcosHundidos = 0;
    ColaDePilas* posiciones = new ColaDePilas(); 
    Pila* sigDisparo;
    
    cargarDisparosConsecutivos(posiciones);
    //cargarDisparosAleatorios(posiciones);
    //cargarDisparosConsecutivos2(posiciones)

    //Iprime las posiciones en las que va a disparar
    //cout<<"---------IMPRIMO LAS POSICIONES---------" <<endl;
    //posiciones->imprimir();
    
    // ---- Empiezo a disparar -----
    while(barcosHundidos < n_barcos)
    {
        int fil = posiciones->tope()->tope()->get_fila();           //Extraigo la fila de la posicion proxima a disparar
        int col = posiciones->tope()->tope()->get_col();            //Extraigo la columna de la posicion proxima a disparar

        //Pregunto si ya se realizo algun disparo en esa posicion
        if(!tablero[fil][col]){                                     
            disp_realizados++;
            sigDisparo = posiciones->tope();             
            primerDisparo(sigDisparo);
        }
        posiciones->desencolar();                                   
        
        //Pregunto si quedan posiciones (En el caso de que haya menos barcos en el tablero)
        if(posiciones->colavacia()){
            cout << "Llegue al final del tablero" <<endl <<endl;
            break;
>>>>>>> emanuel
        }
    }
    

<<<<<<< HEAD
    cout<<"Cargue los datos correctamente" <<endl;
    
    cout<<"---------IMPRIMO LAS POSICIONES---------" <<endl;
    posiciones->imprimir();

    //cout << "Llegue al final" <<endl;

   
    
    //while(barcosHundidos < 10)
    //{
        /*
    sigDisparo = posiciones->tope();             
    posiciones->desencolar();
    disparo(sigDisparo);
    
    //}
 
<<<<<<< HEAD
=======
    if(barcosHundidos == n_barcos){
        cout << "Todos los barcos hundidos" <<endl<<endl;
        cout << "Las posiciones de los barcos son las siguientes: " <<endl;
        
        for(int i=0; i < barcosHundidos; i++){
            barcos[i].imprimeBarco();
        }
    cout << "Se encontraron todos los barcos en " << disp_realizados <<" disparos" <<endl;
    }
>>>>>>> emanuel

=======
*/
>>>>>>> c70a39139189c1c0ba2cb43b46d78958fdd0d4d2
    
    cout <<"Llegue al final" <<endl;
    system("PAUSE");
}


//-----------------------METODOS DE LA CLASE PRINCIPAL-----------------------

void primerDisparo (Pila* p){
    char estado;
    int fila = p->tope()->get_fila();                                           //extraigo la fila donde voy a realizar el primer disparo
    int columna = p->tope()->get_col();                                         //extraigo la columna donde voy a realizar el primer disparo

    //----Pregunto el estado de la fila y columna a la que disparo
    cout << "Disparo en fila: " << fila <<" y columna: " <<columna <<endl;        
    cout << "Indique estado: ";
    cin  >> estado;

    switch(estado)
    {
        case 'a':
            p->desapilar();
            tablero[fila][columna] = true;
        break;

        case 'v':
            tablero[fila][columna] = true;
            barcos[barcosHundidos].set_pos(0, fila, columna);
            apilarVecinos(p);
            segundoDisparo(p, fila, columna);
        break;

        case 'h':
            tablero[fila][columna] = true;
            barcos[barcosHundidos].set_pos(0, fila, columna);
            barcos[barcosHundidos].set_tipo(0);
            barcosHundidos++;
            anularVecinos(p);
            cout << "Submarino hundido" <<endl;
        break;
    
        //Vuelve a llamar a la misma funcion si digita una letra que no sea a, v o h
        default: 
            cout << "Ingreso una letra incorrecta, digite nuevamente: " <<endl;
            primerDisparo(p);
    }
    
}

void segundoDisparo(Pila* p, int fil1, int col1){               //fil y col de la posicion del disparo anterior
    
    int fila2 = p->tope()->get_fila();                          //Fila donde voy a realizar el segundo disparo consecutivo
    int columna2 = p->tope()->get_col();                        //Columna donde voy a realizar el segundo disparo consecutivo
    char estado;
    int fila = p->tope()->get_fila();                   //extraigo la fila donde voy a disparar
    int columna = p->tope()->get_col();                 //extraigo la columna donde voy a disparar

<<<<<<< HEAD

    cout << "Disparo en fila: " << fila <<" y columna: " <<columna <<endl;        //pregunto el estado de la fila y columna a la que disparo
    cout << "Indique estado:";
=======
    //----Pregunto el estado de la fila y columna del segundo disparo
    cout << "Disparo en fila: " << fila2 <<" y columna: " <<columna2 <<endl;        
    cout << "Indique estado: ";
>>>>>>> emanuel
    cin  >> estado;

    switch(estado){
    
        case 'a':
<<<<<<< HEAD
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
=======
            tablero[fila2][columna2] = true;
            p->desapilar();
            segundoDisparo(p, fil1, col1);                      //Llamo nuevamente a segundo disparo con la fila y columna del disparo anterior
        break;

        case 'v':
            tablero[fila2][columna2] = true;
            barcos[barcosHundidos].set_pos(1, fila2, columna2);
            
            //El disparo averiado fue en la posicion de ARRIBA con respecto al disparo anterior
            if(fila2<fil1){                                                  
                apilarNvoDisparo(p, fila2+2, columna2);                     //Apilo la posicion de abajo primero por si debo cambiar de direccion
                apilarNvoDisparo(p, fila2-1, columna2);                     //Apilo la posicion de arriba
                anularCasillero(fila2, columna2+1);                         //Anulo la posicion del tablero para no disparar mas adelante
                anularCasillero(fila2, columna2-1);                         //Anulo la posicion del tablero para no disparar mas adelante
                
            }

            //El disparo averiado fue en la posicion de ABAJO con respecto al disparo anterior
            if(fila2>fil1){                                                  
                apilarNvoDisparo(p, fila2-2, columna2);
                apilarNvoDisparo(p, fila2+1, columna2);
                anularCasillero(fila2, columna2+1);
                anularCasillero(fila2, columna2-1);
            }

            //El disparo averiado fue en la posicion de la IZQUIERDA con respecto al disparo anterior
            if(columna2<col1){                                               
                apilarNvoDisparo(p, fila2, columna2+2);
                apilarNvoDisparo(p, fila2, columna2-1);
                anularCasillero(fila2+1, columna2);
                anularCasillero(fila2-1, columna2);
            }

            //El disparo averiado fue en la posicion de la DERECHA con respecto al disparo anterior
            if(columna2>col1){                                               
                apilarNvoDisparo(p, fila2, columna2-2);
                apilarNvoDisparo(p, fila2, columna2+1);
                anularCasillero(fila2+1, columna2);
                anularCasillero(fila2-1, columna2);
            }
            tercerDisparo(p, fila2, columna2);
        break;

        case 'h':
            tablero[fila2][columna2] = true;
            barcos[barcosHundidos].set_pos(1, fila2, columna2);
            barcos[barcosHundidos].set_tipo(1);
            barcosHundidos++;
            anularVecinos(p);
            cout << "Canionera hundida" <<endl;
        break;

        //Vuelve a llamar a la misma funcion si digita una letra que no sea a, v o h
        default: 
            cout << "Ingreso una letra incorrecta, digite nuevamente: " <<endl;
            segundoDisparo(p, fil1, col1);
    }
}

void tercerDisparo(Pila* p, int fila2, int columna2){
    int fila3 = p->tope()->get_fila();
    int columna3 = p->tope()->get_col();
    char estado;

    //----Pregunto el estado de la fila y columna del segundo disparo
    cout << "Disparo en fila: " << fila3 <<" y columna: " <<columna3 <<endl;
    cout << "Indique estado: ";
    cin  >> estado;

    switch(estado){
        case 'a':
            tablero[fila3][columna3] = true;
            p->desapilar();
            tercerDisparo(p, fila2, columna2);
        break;

        case 'v':
            tablero[fila3][columna3] = true;
            barcos[barcosHundidos].set_pos(2, fila3, columna3);

            //El disparo averiado fue en la posicion de ARRIBA con respecto al disparo anterior
            if(fila3<fila2){
                apilarNvoDisparo(p, fila3+3, columna3);
                apilarNvoDisparo(p, fila3-1, columna3);
                anularCasillero(fila3, columna3+1);
                anularCasillero(fila3, columna3-1);
            }

<<<<<<< HEAD
            //El disparo averiado fue en la posicion de ABAJO con respecto al disparo anterior
            if(fila3>fila2){
                apilarNvoDisparo(p, fila3-3, columna3);
                apilarNvoDisparo(p, fila3+1, columna3);
                anularCasillero(fila3, columna3+1);
                anularCasillero(fila3, columna3-1);
            }

            //El disparo averiado fue en la posicion de la DERECHA con respecto al disparo anterior
            if(columna3>columna2){
                apilarNvoDisparo(p, fila3, columna3-3);            
                apilarNvoDisparo(p, fila3, columna3+1);
                anularCasillero(fila3+1, columna3);
                anularCasillero(fila3-1, columna3);     
            }

            //El disparo averiado fue en la posicion de la IZQUIERDA con respecto al disparo anterior
            if(columna3<columna2){
                apilarNvoDisparo(p, fila3, columna3+3);
                apilarNvoDisparo(p, fila3, columna3-1);
                anularCasillero(fila3+1, columna3);
                anularCasillero(fila3-1, columna3); 
            }
        cuartoDisparo(p);
        break;

        case 'h':
            tablero[fila3][columna3] = true;
            barcos[barcosHundidos].set_pos(2, fila3, columna3);
            barcos[barcosHundidos].set_tipo(2);
            barcosHundidos++;
            anularVecinos(p);
            cout << "Crucero hundido" <<endl;
        break;

        //Vuelve a llamar a la misma funcion si digita una letra que no sea a, v o h
        default:
            cout << "Ingreso una letra incorrecta, digite nuevamente: " <<endl;
            tercerDisparo(p, fila2, columna2);
    }

}

void cuartoDisparo(Pila* p){
    int fila4 = p->tope()->get_fila();
    int columna4 = p->tope()->get_col();
    char estado;

    //----Pregunto el estado de la fila y columna del segundo disparo
    cout << "Disparo en fila: " << fila4 <<" y columna: " <<columna4 <<endl;
    cout << "Indique estado: ";
    cin  >> estado;

    switch(estado){
        case 'a':
            tablero[fila4][columna4] = true;
            p->desapilar();
            cuartoDisparo(p);
        break;

        case 'h':
            cout << "Destructor hundido" <<endl;
            tablero[fila4][columna4] = true;
            barcos[barcosHundidos].set_pos(3, fila4, columna4);
            barcos[barcosHundidos].set_tipo(3);
            barcosHundidos++;
            anularVecinos(p);
        break;

        //Vuelve a llamar a la misma funcion si digita una letra que no sea a, v o h
        default:
            cout << "Ingreso una letra incorrecta, digite nuevamente: " <<endl;
            cuartoDisparo(p);

    }
}

//----Cargo la pila de disparos iniciales a la cola de manera CONSECUTIVA del 
void cargarDisparosConsecutivos(ColaDePilas* pos){
    for(int i=0; i<filasTablero; i++){                                       
        for(int j=0; j<colTablero; j++){
            tablero[i][j] = false;
            Pila* nuevo = new Pila();
            nuevo->apilar(i, j); 
            pos->encolar(nuevo);
        }
    }
}

//----Cargo la pila de disparos iniciales a la cola de manera CONSECUTIVA desde el final
void cargarDisparosConsecutivos2(ColaDePilas* pos){
    for(int i=filasTablero; i>0; i--){                                       
        for(int j=colTablero; j>0; j--){
            tablero[i][j] = false;
            Pila* nuevo = new Pila();
            nuevo->apilar(i, j); 
            pos->encolar(nuevo);
        }
    }
}

//----Cargo la pila de disparos iniciales a la cola de manera ALEATORIA
void cargarDisparosAleatorios(ColaDePilas* pos){
    bool asignados[10][10]={false};
    for(int i=0; i<filasTablero; i++){
        for(int j=0; j<colTablero; j++){
          	int a,b;
          	do {
          		a=rand()%10;
          		b=rand()%10;
			}while(asignados[a][b]);        //Verifico que el numero generado no este repetido

          	asignados[a][b]=true;
			tablero[a][b] = false;

            Pila* nuevo = new Pila();
            nuevo->apilar(a, b); 
            pos->encolar(nuevo);
        }
>>>>>>> emanuel
    }
}

//----Apilo las posiciones de alrededor de la posicion
void apilarVecinos(Pila* p){
    int fila, columna;
    fila = p->tope()->get_fila();
    columna = p->tope()->get_col();

    apilarNvoDisparo(p, fila-1, columna);           // Apilo la posicion de ARRIBA
    apilarNvoDisparo(p, fila+1, columna);           // Apilo la posicion de ABAJO
    apilarNvoDisparo(p, fila, columna-1);           // Apilo la posicion de IZQUIERDA
    apilarNvoDisparo(p, fila, columna+1);           // Apilo la posicion de DERECHA
}

//----Apilo posiciones en el lugar especificado
void apilarNvoDisparo(Pila* p, int fil, int col){
    if(fil<=9 && fil>=0 && col>=0 && col<=9){               // Compruebo que la posicion a apilar esta dentro del tablero
        if(tablero[fil][col] != true)                       // Compruebo que en la posicion a apilar no se diparo antes
            p->apilar(fil, col);                            // Apilo la nueva posicion             
        
    }
}

//----Marco como true las posiciones vecinas a los barcos para no realizar disparos innesecarios
void anularVecinos(Pila* p){
    int fila, columna;
    fila = p->tope()->get_fila();
    columna = p->tope()->get_col();

    anularCasillero(fila-1, columna);
    anularCasillero(fila+1, columna);
    anularCasillero(fila, columna-1);
    anularCasillero(fila, columna+1);

}

//----Anulo un casillero en un lugar especifico
void anularCasillero(int fil, int col){
    if(fil<=9 && fil>=0 && col>=0 && col<=9)
        tablero[fil][col] = true;
=======
>>>>>>> c70a39139189c1c0ba2cb43b46d78958fdd0d4d2
}
