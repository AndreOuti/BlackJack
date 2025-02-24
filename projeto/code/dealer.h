#ifndef DEALER_H
#define DEALER_H
#include "Jogador.h"
#include "Mao.h"
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
    void resetarMao();
    Mao&  getMao() { return maoDealer; }
    void limparMao();
};

#endif




