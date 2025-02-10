#include "Jogo.h"
#include <iostream>

Jogo::Jogo(int numJogadores, int saldoInicial) : baralho(8) {
    for (int i = 0; i < numJogadores; i++) {
        jogadores.emplace_back("Jogador " + std::to_string(i + 1), saldoInicial);
    }
    baralho.embaralhar();
}

void Jogo::distribuirCartas() {
    for (auto& jogador : jogadores) {
        jogador.adicionarCarta(baralho.distribuirCarta());
        jogador.adicionarCarta(baralho.distribuirCarta());
    }
    dealer.jogadaDealer(baralho);
}

void Jogo::resolverRodada() {
    for (auto& jogador : jogadores) {
        if (jogador.isAtivo()) {

            jogador.calcularPontuacao();
        }
    }
    dealer.calcularPontuacao();
}

