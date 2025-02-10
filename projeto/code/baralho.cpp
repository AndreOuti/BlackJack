#include "Baralho.h"
#include <stdexcept> //usar o out of range


Baralho::Baralho(int numBaralhos) {
    const string naipes[] = {"Copas", "Espadas","Ouros", "Paus"};   //array de strings
    for (int i = 0; i<numBaralhos;i++) {    //laço do numero de baralhos
        for (const auto& naipe : naipes){   //laço para os naipes de cada carta
            for(int valor=1; valor<=13;valor++){  // laço o valor de cada carta
                cartas.emplace_back(naipe,valor);  //adiciona uma carta no final do vetor
            }
        }
    }
}

    void Baralho::embaralhar(){
        random_device rd; //gera uma semente aleatória
        mt19937 g(rd());  //Cria um gerador de números aleatórios
        shuffle(cartas.begin(),cartas.end(),g); //embaralha as cartas
    }
    Carta Baralho::distribuirCarta(){
        if (!cartas.empty()){
            Carta carta = cartas.back();  //retorna a última carta do vetor cartas
            cartas.pop_back();  //remove a última carta do vetor
            return carta;
    }
    throw out_of_range("Baralho vazio.");
}
