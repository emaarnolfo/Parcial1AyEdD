#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Listas02.h"

using namespace std;


#define MaxCola 100
class Cola{
      private:
              Pila* v[MaxCola];
              int ult;
<<<<<<< HEAD
      public:
      Cola(void){ult = 0;}
=======
              int frente;
      public:
      Cola(void){ult = -1; frente=-1;}
>>>>>>> emanuel
      Pila* tope();
      bool colavacia();
      void encolar(Pila* a) ;
      void desencolar();
      void imprimir();
};

Pila* Cola::tope(){
    if(colavacia()){
                    cout<<endl<<"TOPE: ERROR cola vacia"<<endl;
                    return NULL;
    }
<<<<<<< HEAD
    else return v[0];
}

bool Cola::colavacia(){
     return ult == 1;
=======
    else return v[frente];
}

bool Cola::colavacia(){
     return ult == -1;
>>>>>>> emanuel
}

void Cola::encolar(Pila* a){
     if (ult<MaxCola){
     v[ult]=a;
     ult++;
     } 
     else cout<<"ENCOLAR: ERROR cola llena"<<endl;
}
void Cola::desencolar(){
     for(int i=0;i<ult;i++)
             v[i]=v[i+1];
     ult--;
}

void Cola::imprimir(){
     while(!this->colavacia()){
          this->tope()->impre();
          this->desencolar();
     }
     cout<<"Cola vacia" <<endl;
}
