#include "Dealer.h"
#include <QMessageBox>

void Dealer::jogadaDealer(Baralho& baralho) {
    // Enquanto a pontuação do dealer for inferior a 17, ele continua comprando cartas
    while (maoDealer.calcularPontuacao() < 17) {
        Carta carta = baralho.distribuirCarta(); // Distribui uma carta do baralho
        qDebug() << "Dealer recebe carta: " << carta.getNaipe().c_str() << carta.getValor();

        // Adiciona a carta à mão do dealer
        maoDealer.adicionarCarta(carta);

        // Exibe a carta do dealer no console (caso necessário)
        qDebug() << "Dealer tem agora " << maoDealer.calcularPontuacao() << " pontos";
    }
}

void Dealer::limparMao() {
    maoDealer.limpar();
}
