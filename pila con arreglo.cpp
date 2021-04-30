#include <iostream>
#include <sstream>
#define MAX 10

using namespace std;
typedef long int tipolista;
class Pila{
      private:
              tipolista v[MAX];
              int p;
      public:
             Pila();
             void apilar(tipolista x);
             tipolista tope(void);
             void desapilar(void);
             bool pilavacia();
};

Pila::Pila()
{p=-1;
}
void Pila::apilar(tipolista x)
{  if(p<MAX-1)v[++p]=x;
   else cout<<"ERROR pila llena"<<endl;
}
tipolista Pila::tope()
{  if(!pilavacia()) return v[p];
   cout<<"La pila esta vacia";
   return "";
}
void Pila::desapilar()
{ if(!pilavacia()) --p;
}
bool Pila::pilavacia()
{ return p<0;
}

int main()
{

     cout<<endl;
     system("PAUSE");
     return 0;
}
