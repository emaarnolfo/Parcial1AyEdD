#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

typedef int tipolista;
//------------------------------------------------------------------------

#define MaxCola 30
class Cola{
      private:
              tipolista v[MaxCola];
              int ult;
      public:
      Cola(void){ult=-1;}
      tipolista tope();
      bool colavacia();
      void encolar(tipolista a) ;
      void desencolar();
};

tipolista Cola::tope(){
    if(colavacia()){
                    cout<<endl<<"ERROR cola vacia"<<endl;
                    return -1;
    }
    else return v[0];
}

bool Cola::colavacia(){
     return ult==-1;
}

void Cola::encolar(tipolista a){
     if (ult<MaxCola-1) v[++ult]=a;
     else cout<<"ERROR cola llena"<<endl;
}
void Cola::desencolar(){
     for(int i=0;i<ult;i++)
             v[i]=v[i+1];
     ult--;
}


int main(){
    Cola *c=new Cola();
    if (c->colavacia()) cout<<endl<<"La cola esta VACIA"<<endl;
    c->encolar(1);
    c->encolar(2);
    c->encolar(3);

    cout<<"en cola:"<<c->tope()<<endl;
    c->desencolar();

    cout<<"en cola:"<<c->tope()<<endl;
    c->desencolar();

    cout<<"en cola:"<<c->tope()<<endl;
    c->desencolar();

    c->encolar(444);
    cout<<"en cola:"<<c->tope()<<endl;
    c->desencolar();
    cout<<"en cola:"<<c->tope()<<endl;

    system("PAUSE");
    return EXIT_SUCCESS;

}
