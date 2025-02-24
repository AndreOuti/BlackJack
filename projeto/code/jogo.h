#ifndef JOGO_H
#define JOGO_H

#include "Jogador.h"
#include "Dealer.h"
#include "Baralho.h"
#include <vector>

class Jogo
{
private:
    vector<Jogador> jogadores;
    Dealer dealer;
    Baralho baralho;



public:
    Jogo(int numJogadores, int saldoInicial = 1000);
    void distribuirCartas();
    void resolverRodada();
    std::vector<Jogador>& getJogadores() { return jogadores; }
    Baralho& getBaralho();
    Dealer& getDealer() { return dealer; }
    void resetarJogo();

};

#endif // JOGO_H
