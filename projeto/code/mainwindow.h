#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog> // Para usar os diálogos de entrada
#include "jogo.h"

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
    void iniciarJogo();  // Método para iniciar o jogo

    void updateSaldo();

private:
    Ui::MainWindow *ui;
    QPushButton *btnHit;
    QPushButton *btnStand;
    QPushButton *btnDouble;

    QLabel *saldoLabel;// Label para exibir o saldo

    // Funções para solicitar o número de jogadores e o saldo
    int numJogadores;  // Número de jogadores
    double saldoInicial;  // Saldo inicial

    // Objeto Jogo
    Jogo* jogo;
};

#endif // MAINWINDOW_H
