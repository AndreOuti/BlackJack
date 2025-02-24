#include "Mao.h"


int Mao::calcularPontuacao() const {
    int soma = 0;
    int ases = 0;

    for (const auto& carta : mao) {     // percorre o vetor de cartas da mao
        if (carta.getValor() > 10) {
            soma += 10; // Valete, Dama e Rei valem 10
        } else if (carta.getValor() == 1) {
            ases++; // Contar os Ases como 11
            soma += 11; // Tratar inicialmente como 11
        } else {
            soma += carta.getValor(); //cartas 2 a 10 o valor é msm
        }
    }

    while (soma > 21 && ases > 0) { //ver se estorou
        soma -= 10; // tirar 10
        ases--;     //considera as como 1
    }

    return soma;
}
