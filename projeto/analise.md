# Análise orientada a objeto
> [!NOTE]
> A **análise** orientada a objeto consiste na descrição do problema a ser tratado, duas primeiras etapas da tabela abaixo, a definição de casos de uso e a definição do domínio do problema.

## Descrição Geral do domínio do problema

O projeto consiste em criar um jogo de Blackjack, onde o jogador enfrentará um dealer controlado pelo sistema. O jogo permite ao usuário escolhe suas ações no jogo. O objetivo é criar o Blackjack tradicional, em que o jogador tenta alcançar 21 pontos ou se aproximar desse valor sem ultrapassá-lo.
O sistema será responsável por controlar todas as mecânicas do jogo, como a distribuição de cartas, o cálculo de pontuações, a gestão das apostas e as ações possíveis para o jogador: hit (pedir carta), stand (manter a mão) e double down (dobrar a aposta e receber mais uma carta). Além disso, será responsável por avaliar automaticamente as condições de vitória, derrota ou empate ao final de cada rodada.
O dealer seguirá as regras clássicas do Blackjack, comprando cartas até atingir pelo menos 17 pontos. O jogo termina quando um jogador decide sair.

Requisitos funcionais:


Distribuir cartas de forma aleatória para os jogadores e o dealer.
Implementar as ações disponíveis ao jogador: hit, stand e double down.
Gerenciar a pontuação e avaliar as condições de vitória, derrota ou empate.
Reiniciar caso jogador queira.

Requisitos não-funcionais:

Interface intuitiva para o usuário.

## Diagrama de Casos de Uso

![image](https://github.com/user-attachments/assets/def60215-7b23-46cf-a5cd-946ba6a061b9)




## Diagrama de Domínio do problema

![image](https://github.com/user-attachments/assets/56a8a0cc-d48f-4466-a773-5e45f3506a86)



<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>
