#ifndef BARALHO_H
#define BARALHO_H

#include "Carta.h"
#include <vector>
#include <algorithm>
#include <random>


class Baralho {
private:
    vector<Carta> cartas;

public:
    Baralho(int numBaralhos =8);
    void embaralhar();
    Carta distribuirCarta();
};

#endif // BARALHO_H
