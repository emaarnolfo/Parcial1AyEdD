#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Barco {
    private:
        int pos[4];
        string tipo;

    public: 
        Barco(){};
        Barco(string tipo);
};

Barco::Barco(string nombre){
    tipo = nombre;
}

