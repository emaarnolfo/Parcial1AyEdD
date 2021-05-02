#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef struct{
    bool f=false;
    bool c=false;
   /* int f;
    int c;*/
} pos;

class Barco {
    private:
        pos a[4];
        char tipo[10];  //cambie de string a char porque sino no funciona el strcpy
        int size;
    public:
        Barco();
        void impreBarco();   
        void tablero(); 
};

Barco::Barco(){
    cout<<"Ingrese el número de acuerdo al tipo de barco: "<<endl
        <<"1. si es submarino"<<endl<<"2. si es cañonera"<<endl<<"3. si es crucero"<<endl<<"4. si es destructor"<<endl;
    cin>>size;
    for(int i=0; i<size;i++){
        cout<<"Ubicado en la posicion: ";
        cout<<"Fila: "; cin>>a[i].f;
        cout<<"Columna: "; cin>>a[i].c;
    }
    cout << "\n";
    switch (size){
    case 1:
        strcpy(tipo, "Submarino");  //strcpy sirve para cadena de caracteres declarados como char, no para un string
        break;
    case 2:
        strcpy(tipo, "Cañonera");
        break;
    case 3:
        strcpy(tipo, "Crucero");
        break;
    case 4:
        strcpy(tipo, "Destructor");
        break;
    }
}

void Barco::impreBarco(){
    cout << "El barco es un: " << tipo << " y su longitud es: " << size << endl;
    cout << "Las posiciones correspondientes son: ";
    for (int i = 0; i<size; i++) 
        cout << "{" << a[i].f << "," << a[i].c << "} ";
/*
    //el tablero se vería
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(a[i].f==false && a[j].c==false){cout<<"0"<<" ";}
            else cout<<"1"<<" ";
        }
        cout<<endl;
    }  
    */
}
