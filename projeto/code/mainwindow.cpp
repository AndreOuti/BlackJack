#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QMessageBox>  // Para mostrar mensagens
#include <QInputDialog>  // Para capturar dados do usuário

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    numJogadores = 1;  // Número de jogadores
    saldoInicial = 1000;  // Saldo inicial

    // Configurações da janela
    setWindowTitle("Blackjack");
    setFixedSize(800, 600);  // Tamanho fixo da janela

    // Criar e configurar a QLabel para a mesa
    QLabel *mesaLabel = new QLabel(this);
    QPixmap mesaPixmap(":/Imgs/Imagens/mesa.png");  // Caminho da imagem no recurso
    mesaLabel->setPixmap(mesaPixmap);
    mesaLabel->setScaledContents(true);
    mesaLabel->setGeometry(0, 0, width(), height());

    // Criando os botões
    btnHit = new QPushButton("Hit", this);
    btnStand = new QPushButton("Stand", this);
    btnDouble = new QPushButton("Double", this);

    // Definindo a geometria dos botões (posição e tamanho)
    btnHit->setGeometry(50, 500, 100, 40);
    btnStand->setGeometry(160, 500, 100, 40);
    btnDouble->setGeometry(270, 500, 100, 40);

    // Conectando os botões aos slots
    connect(btnHit, &QPushButton::clicked, this, &MainWindow::onHitClicked);
    connect(btnStand, &QPushButton::clicked, this, &MainWindow::onStandClicked);
    connect(btnDouble, &QPushButton::clicked, this, &MainWindow::onDoubleClicked);

    // Criando o label para mostrar o saldo
    saldoLabel = new QLabel("Saldo: R$ 1000", this);
    saldoLabel->setGeometry(50, 20, 200, 40);  // Defina a posição e o tamanho do label

    jogo = new Jogo(1, 1000);  // 1 jogador, saldo inicial 1000
    // Atualiza o saldo ao iniciar o jogo
    updateSaldo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciarJogo() {
    // Solicitar o número de jogadores e o saldo inicial

    if (numJogadores > 0 && saldoInicial > 0) {
        jogo = new Jogo(numJogadores, saldoInicial); // Cria o jogo com as entradas
        QMessageBox::information(this, "Jogo Iniciado", "O jogo foi iniciado com sucesso!");
    } else {
        QMessageBox::warning(this, "Entrada inválida", "Por favor, insira valores válidos.");
    }
}




void MainWindow::onHitClicked()
{
    // Lógica para a ação "Hit"
    qDebug() << "Ação: Hit";
}

void MainWindow::onStandClicked()
{
    // Lógica para a ação "Stand"
    qDebug() << "Ação: Stand";
}

void MainWindow::onDoubleClicked()
{
    // Lógica para a ação "Double"
    qDebug() << "Ação: Double";
}

void MainWindow::updateSaldo()
{
    // Atualiza o saldo do jogador no label
    saldoLabel->setText("Saldo: R$ " + QString::number(jogo->getJogadores()[0].getSaldo()));
}
