#ifndef MAO_H
#define MAO_H

#include "Carta.h"
#include <vector>


class Mao {
private:
    vector<Carta> cartas;

public:
    void adicionarCarta(const Carta& carta) { cartas.push_back(carta); }
    int calcularPontuacao() const;
    void limpar() { cartas.clear(); }
};

#endif // MAO_H
