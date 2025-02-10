#include "Dealer.h"


void Dealer::jogadaDealer(Baralho& baralho) {
    while (maoDealer.calcularPontuacao() < 17) {
        maoDealer.adicionarCarta(baralho.distribuirCarta());
    }
}


