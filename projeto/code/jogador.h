#ifndef JOGADOR_H
#define JOGADOR_H
#include "Mao.h"

class Jogador
{
private:
    string nome;
    int saldo;
    int aposta;
    Mao maoJogador;
    bool ativo;  //se o jogador pode fazer alguma coisa

public:
    Jogador(string nome,int saldo);

    string getNome()const;
    int getSaldo()const;
    Mao& getMao() { return maoJogador; }

    int getAposta() const;
    void setAposta(int aposta);

    void adicionarCarta(const Carta& carta);
    void limparMao();
    void limparStatus();
    void setAtivo(bool status) {
        ativo = status;
    }
    bool isAtivo()const;
    void hit(Baralho& baralho);
    void doubleDown(Baralho& baralho);
    void stand();
    void resetarMao();

    void atualizarSaldo(bool venceu);
    int calcularPontuacao() const {
        return maoJogador.calcularPontuacao();  // Chama o método da classe Mao
    }


};

#endif // JOGADOR_H
