#include "Jogo.h"


Jogo::Jogo(int numJogadores, int saldoInicial) : baralho(8) {
    for (int i = 0; i < numJogadores; i++) {
        jogadores.emplace_back("Jogador " + std::to_string(i + 1), saldoInicial);
    }
    baralho.embaralhar();

}

Baralho& Jogo::getBaralho() {
    return baralho;
}

void Jogo::distribuirCartas() {
    for (auto& jogador : jogadores) {
        jogador.adicionarCarta(baralho.distribuirCarta());
        jogador.adicionarCarta(baralho.distribuirCarta());
    }

    dealer.jogadaDealer(baralho);
}


void Jogo::resolverRodada() {
    int pontosDealer = dealer.calcularPontuacao();

    for (auto& jogador : jogadores) {
        int pontosJogador = jogador.calcularPontuacao();
        if (pontosJogador > 21) {
            jogador.atualizarSaldo(false); // Perdeu
        } else if (pontosDealer > 21 || pontosJogador > pontosDealer) {
            jogador.atualizarSaldo(true); // Ganhou
        } else {
            jogador.atualizarSaldo(false); // Perdeu
        }
    }
}

