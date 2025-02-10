#ifndef DEALER_H
#define DEALER_H
#include "Jogador.h"
#include "Mao.h"
#include "Baralho.h"
#include "Jogador.h"
#include<vector>

class Dealer
{
private:
    Mao maoDealer;
public:
    void jogadaDealer(Baralho& baralho);

    int calcularPontuacao() const {
        return maoDealer.calcularPontuacao();  // Chama o método da classe Mao
    }

};

#endif




