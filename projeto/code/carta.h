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
    Carta(string naipe, int valor) : naipe(naipe), valor(valor) {}  //construtor controi a carta com naipe e um valor

    string getNaipe(){return naipe;}
    int getValor() const {return valor;}
};

#endif // CARTA_H
