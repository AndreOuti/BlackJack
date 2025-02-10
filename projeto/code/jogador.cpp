#include "Jogador.h"
#include <stdexcept>

Jogador::Jogador(string nome, int saldo)
    : nome(nome),saldo(saldo),aposta(0),ativo(true) {}

string Jogador::getNome() const{
    return nome;
}

int Jogador:: getSaldo() const{
    return saldo;
}

int Jogador :: getAposta() const{
    return aposta;
}

void Jogador :: setAposta(int aposta){
    if(aposta<=saldo){
        this->aposta = aposta;
    }else{
        throw std::invalid_argument("Saldo insuficiente para a aposta.");
    }
}

void Jogador:: limparStatus(){
    ativo=true;
}

bool Jogador:: isAtivo() const{
    return ativo;
}


void Jogador:: hit(Baralho& baralho){
    if(ativo){
        adicionarCarta(baralho.distribuirCarta());
        if(maoJogador.calcularPontuacao() > 21){
        ativo = false;
        }
    }
}

void Jogador::stand(){
        ativo=false;
}

void Jogador::doubleDown(Baralho& baralho) {
    if (ativo && saldo >= aposta*2) {
        aposta *= 2;
        adicionarCarta(baralho.distribuirCarta());
        ativo = false;
    } else {
        throw std::invalid_argument("Não é possível fazer Double Down.");
    }
}

void Jogador::atualizarSaldo(bool venceu) {
    if (venceu) {
        saldo += aposta;  // O jogador ganha a aposta
    } else {
        saldo -= aposta;  // O jogador perde a aposta
    }
    aposta = 0;  // Reseta a aposta após a rodada
}

void Jogador::adicionarCarta(const Carta& carta){
    maoJogador.adicionarCarta(carta);
}

void Jogador::limparMao() {
    maoJogador.limpar();
}

