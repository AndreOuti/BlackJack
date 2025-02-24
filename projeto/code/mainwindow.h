#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog> // Para usar os diálogos de entrada
#include "jogo.h"
#include <QHBoxLayout>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onHitClicked();
    void onStandClicked();
    void onDoubleClicked();
    void onIniciarJogoClicked();
    void iniciarJogo();  // Método para iniciar o jogo

    void updateSaldo();

    void exibirCarta(const QString& caminhoImagem, int x, int y);  // Método para exibir cartas

    //void adicionarCartaJogador(const QString &nomeArquivo);
    //void adicionarCartaDealer(const QString &nomeArquivo);
   // void limparCartasJogador();
    //void limparCartasDealer();

    // Função para exibir as cartas da mão do jogador
     void exibirCartasMao(std::vector<Carta>& mao, int xInicial, int y);
    // Função para exibir o verso da carta (para o dealer)
     void exibirCartaVerso(int x, int y);
     void onReiniciarClicked();

private:
    Ui::MainWindow *ui;
    QPushButton *btnHit;
    QPushButton *btnStand;
    QPushButton *btnDouble;
    QPushButton *btnIniciarJogo;  // Botão para iniciar o jogo
    void exibirCartasDealer1(std::vector<Carta>& mao, int xInicial, int y);
    void exibirCartasDealer(std::vector<Carta>& mao, int xInicial, int y);
    std::vector<QLabel*> dealerCartasLabels; // Para armazenar as cartas do dealer
    QPushButton* btnReiniciar;

    QLabel *saldoLabel;// Label para exibir o saldo
    QLabel *jogadorLabel;// Label para exibir o saldo

    // Declaração das variáveis para exibir as pontuações
    QLabel* pontuacaoJogadorLabel;
    QLabel* pontuacaoDealerLabel;


    // Funções para solicitar o número de jogadores e o saldo
    int numJogadores;  // Número de jogadores
    double saldoInicial;  // Saldo inicial

    // Objeto Jogo
    Jogo* jogo;

    //std::vector<QLabel*> cartasJogador; // Labels para as cartas do jogador
    //std::vector<QLabel*> cartasDealer;  // Labels para as cartas do dealer

    //QHBoxLayout *layoutCartasJogador;
    //QHBoxLayout *layoutCartasDealer;

    QLabel* cartaLabel;  // Variável para armazenar o QLabel da carta
    QLabel* cartaVersoLabel = nullptr; // Adicione esta variável como membro da classe MainWindow

    std::vector<QLabel*> cartasLabels;
    QPushButton* btnJogarNovamente;
};

#endif // MAINWINDOW_H
