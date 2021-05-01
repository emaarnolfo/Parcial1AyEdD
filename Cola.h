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
              int frente;
      public:
      Cola(void){ult = -1; frente=-1;}
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
    else return v[frente];
}

bool Cola::colavacia(){
     return ult == -1;
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
