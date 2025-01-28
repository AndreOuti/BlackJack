#ifndef CARTA_H
#define CARTA_H

#include <string>
using namespace std;

class Carta
{

private:

    string naipe;
    int valor;

public:

    Carta(string naipe, int valor);   //construtor

    string getNaipe() const { return naipe; } //retorna naipe
    int getValor() const { return valor; }    //retorna valor

};

#endif // CARTA_H
