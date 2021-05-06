
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Nodo {
    private:
        int fila;
        int col;
        Nodo* next;
    public:
        Nodo() { next = 0; };
        Nodo(int x, int y) { fila = x; col = y; next = 0; };
        void set_dato(int x, int y) { fila = x; fila = y; };
        void set_next(Nodo* n) { next = n; };
        int get_fila() { return fila; };
        int get_col() { return col; };
        Nodo* get_next() { return next; };
        bool es_vacio() { return next == 0; };

};

class Lista {
    private:
        Nodo* czo;
    public:
        Lista() { czo = new Nodo(); };
        Lista(Nodo* n) { czo = n; };
        void add(int x, int y);
        bool esvacia(void);
        Nodo* cabeza(void);
        Lista* resto(void);
        string toPrint(string p);
        void impre(void);
        int size();
        bool esta(int x, int y);
        Nodo* last();
        void borrarDato(int x, int y);
        void borrar(void);                      //Borra la cabeza
        void borrar_last();                     //Borra el ultimo
        //void concat(Lista* l1);                 //Le transfiere los datos de l1 a this
       // Lista* copy(void);                     //hace una copia de la lista
        void tomar(int n);                      //deja vivos los n primero nodos y borra el resto
};

void Lista::add(int a, int b)
{
    Nodo* nuevo = new Nodo(a, b);
    nuevo->set_next(czo);
    czo = nuevo;
}

Nodo* Lista::last()
{
    if (!this->esvacia()) {
        if (this->resto()->esvacia())return this->cabeza();
        return this->resto()->last();
    }return 0;
}

bool Lista::esvacia(void)
{
    return czo->es_vacio();
}

Nodo* Lista::cabeza(void)
{
    if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo;
}

Lista* Lista::resto(void)
{
    Lista* l = new Lista(czo->get_next());
    return (l);
}

string Lista::toPrint(string p)
{
    if (this->esvacia()) {
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza()->get_col() <<"-" <<this->cabeza()->get_fila() << "/" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

int Lista::size()
{
    if (this->esvacia()) return 0;
    return 1 + this->resto()->size();
}

void Lista::borrar(void)
{ //borra el nodo cabeza
    if (!this->esvacia()) {
        Nodo* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

void Lista::borrar_last()
{ // borra el ultimo nodo
    if (!this->esvacia()) {
        if ((czo->get_next())->get_next() == NULL) {
            delete czo->get_next();
            czo->set_next(NULL);
        }
        else this->resto()->borrar_last();
    }
}

/*
void Lista::concat(Lista* l1)
{// le transfiere los datos de l1 a this
    if (!(l1->esvacia())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}
*/
/*
Lista* Lista::copy(void)
{
    Lista* aux = new Lista();
    aux->concat(this);
    return aux;
}
*/
void Lista::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}

void Lista::impre(void)
{
    Nodo* aux = new Nodo;
    aux = czo;
    
    while (aux->get_next() != 0) {
        cout <<"Fila: " << aux->get_fila() << " Columna:" <<aux->get_col() <<endl;
        aux = aux->get_next();
    }
}

bool Lista::esta(int a, int b)
{// busca d en la lista
    if (this->esvacia()) return false;
    if (this->cabeza()->get_fila() == a && this->cabeza()->get_col()) return true;

    return this->resto()->esta(a,b);
}
/*
void Lista::borrarD(int d, Nodo* ant)
{
    if (!this->esvacia()) {
        if (d == this->cabeza()) {
            if (ant == NULL) {//al principio
                this->borrar();
            }
            else {//entre medio
                ant->set_next(czo->get_next());
                delete czo;
            }
        }
        else  this->resto()->borrarD(d, czo);

    }
}
*/

class Pila :public Lista {
public:
    Pila() { Lista(); };
    void apilar(int a, int b) { this->add(a, b); };
    Nodo* tope(void) { return this->cabeza(); };
    void desapilar(void) { this->borrar(); };
    bool pilavacia() { return this->esvacia(); };
    void imprimir(){this->impre();}
};
