
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
        Nodo() { next = NULL; };
        Nodo(int x, int y) { fila = x; col = y; next = NULL; };
        void set_dato(int x, int y) { fila = x; fila = y; };
        void set_next(Nodo* n) { next = n; };
        int get_fila() { return fila; };
        int get_col() { return col; };
        Nodo* get_next() { return next; };
        bool es_vacio() { return next == NULL; };

};

class Lista {
    private:
        Nodo* czo;
    public:
        Lista() { czo = new Nodo(); };
        Lista(Nodo* n) { czo = n; };
        ~Lista();
        void add(int x, int y);
        bool esvacia(void);
        int cabeza(void);
        Lista* resto(void);
        string toPrint(string p);
        void impre(void);
        int size();
        bool esta(int x, int y);
        void borrarDato(int x, int y);
        void borrar(void);                      //Borra la cabeza
        void borrar_last();                     //Borra el ultimo
        void concat(Lista* l1);                 //Le transfiere los datos de l1 a this
        Lista* copy(int n);                     //hace una copia de la lista
        void tomar(int n);                      //deja vivos los n primero nodos y borra el resto
};