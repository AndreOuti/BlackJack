#ifndef MAO_H
#define MAO_H

#include <vector>
#include "Baralho.h"

class Mao
{
private:
    std::vector<Carta>mao;  //vetor que armazena as cartas da mao

public:
    void adicionarCarta(const Carta& carta){mao.push_back(carta); } //adicona carta a mao
    int calcularPontuacao() const;
    void limpar(){mao.clear();}
    std::vector<Carta>& getCartas() { return mao; }  // Retorna as cartas da mão
};

#endif // MAO_H

