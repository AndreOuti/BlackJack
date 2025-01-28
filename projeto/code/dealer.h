#ifndef DEALER_H
#define DEALER_H

#include "Jogador.h"
#include "Baralho.h"

class Dealer : public Jogador {
public:
    Dealer() : Jogador("Dealer", 0) {} // Dealer não tem saldo


        // Método para o dealer jogar de acordo com as regras do Blackjack
    void jogar(Baralho& baralho) {
        while (getMao().calcularPontuacao() < 17) {
            adicionarCarta(baralho.distribuirCarta());
        }
    }
};

#endif // DEALER_H
