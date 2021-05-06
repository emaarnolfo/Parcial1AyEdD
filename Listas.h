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
        void impre(void);
        void borrar(void);                      
};

void Lista::add(int a, int b)
{
    Nodo* nuevo = new Nodo(a, b);
    nuevo->set_next(czo);
    czo = nuevo;
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

void Lista::borrar(void)	//borra el nodo cabeza
{ 
    if (!this->esvacia()) {
        Nodo* tmp = czo;
        czo = czo->get_next();
        delete tmp;
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

class Pila :public Lista {
public:
    Pila() { Lista(); };
    void apilar(int a, int b) { this->add(a, b); };
    Nodo* tope(void) { return this->cabeza(); };
    void desapilar(void) { this->borrar(); };
    bool pilavacia() { return this->esvacia(); };
    void imprimir(){this->impre();}
};