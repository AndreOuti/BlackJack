#ifndef BARALHO_H
#define BARALHO_H

#include <vector>
#include "Carta.h"
#include <algorithm>
#include <random>

class Baralho {
private:
    vector<Carta> cartas;  //  vetor q armazena as cartas do baralho
public:
    Baralho(int numBaralhos = 8);  //construtor
    void embaralhar();
    Carta distribuirCarta();
};

#endif // BARALHO_H
