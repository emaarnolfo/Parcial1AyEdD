#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Nodo{
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
<<<<<<< HEAD
        int size();
        bool esta(int x, int y);
        Nodo* last();
        void borrarDato(int x, int y);
        void borrar(void);                     //Borra la cabeza
        void borrar_last();                    //Borra el ultimo
        //void concat(Lista* l1);              //Le transfiere los datos de l1 a this
       // Lista* copy(void);                   //hace una copia de la lista
        void tomar(int n);                     //deja vivos los n primero nodos y borra el resto
=======
        void borrar(void);                      //Borra la cabeza
>>>>>>> emanuel
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
    
<<<<<<< HEAD
    while (aux->get_next() != NULL) {
=======
    while (aux->get_next() != 0) {
>>>>>>> emanuel
        cout <<"Fila: " << aux->get_fila() << " Columna:" <<aux->get_col() <<endl;
        aux = aux->get_next();
    }

}

class Pila :public Lista {
public:
    Pila() { Lista();};
    void apilar(int a, int b) { this->add(a, b); };
    Nodo* tope(void) { return this->cabeza(); };
    void desapilar(void) { this->borrar(); };
    bool pilavacia() { return this->esvacia(); };
    void imprimir(){this->impre();}
};
<<<<<<< HEAD

/*
class Cola :public Lista {
public:
    Cola() { Lista(); };
    ~Cola();
    Nodo* tope() { return this->last(); };
    bool colavacia(void) { return this->esvacia(); };
    void encolar(int a, int b) { this->add(a, b); };
    void desencolar(void) { this->borrar_last(); };
    Nodo* ultimo(void) { return this->cabeza(); };
    string imprimir(string s) { return this->toPrint(s); };
};
*/
=======
>>>>>>> emanuel
