#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Inicializa o jogo
    jogo = new Jogo(1, 1000);
    jogo->distribuirCartas();

    exibirCartasMao(jogo->getJogadores()[0].getMao().getCartas(), 350, 300);

    exibirCartaVerso(420, 180);

    exibirCartasDealer1(jogo->getDealer().getMao().getCartas(), 330, 172);


    // Configurações da janela
    setWindowTitle("Blackjack");
    setFixedSize(800, 600);  // Tamanho fixo da janela

    // Criar e configurar a QLabel para a mesa
    QLabel *mesaLabel = new QLabel(this);
    QPixmap mesaPixmap(":/Imgs/Imagens/mesa.png");  // Caminho da imagem
    mesaLabel->setPixmap(mesaPixmap);
    mesaLabel->setScaledContents(true);
    mesaLabel->setGeometry(0, 0, width(), height());
    mesaLabel->lower();

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

    //Criar, definir geometria e conectar btn reiniciar
    btnReiniciar = new QPushButton("Reiniciar", this);
    btnReiniciar->setGeometry(650, 500, 100, 40);  // Posição do botão
    connect(btnReiniciar, &QPushButton::clicked, this, &MainWindow::onReiniciarClicked);


    // Criar label para mostrar o saldo
    saldoLabel = new QLabel("Saldo: R$ 1000", this);
    saldoLabel->setGeometry(50, 20, 200,80 );  // Defina a posição e o tamanho do label
    // Criando o label para mostrar o nome
    jogadorLabel = new QLabel("Jogador 1", this);
    jogadorLabel->setGeometry(50, 20, 200, 50);


    updateSaldo();             // Atualiza o saldo ao iniciar o jogo
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHitClicked()
{
    //qDebug() << "Hit";
    // Obtém o primeiro jogador
    Jogador& jogador = jogo->getJogadores()[0];

    // Verifica se o jogador ainda está ativo
    if (!jogador.isAtivo()) {
        QMessageBox::warning(this, "Aviso", "Você não pode mais jogar!");
        return;
    }
    // Distribui uma nova carta do baralho
    jogador.hit(jogo->getBaralho());

    // Atualiza a exibição das cartas do jogador
    exibirCartasMao(jogador.getMao().getCartas(), 350, 300);

    // Atualiza o saldo
    updateSaldo();

    // Verifica se o jogador ultrapassou 21 pontos
    if (jogador.calcularPontuacao() > 21) {
        QMessageBox::information(this, "1", "Estorou");
        jogador.stand(); // O jogador automaticamente encerra a jogada
        jogo->getDealer().jogadaDealer(jogo->getBaralho());  // Dealer compra cartas


        // Exibe as cartas do dealer após a jogada
        exibirCartasDealer(jogo->getDealer().getMao().getCartas(), 330, 172);

        if (cartaVersoLabel) {
            delete cartaVersoLabel;  // Remove a carta virada
            cartaVersoLabel = nullptr;  // Libera a memória
        }
    }

}

void MainWindow::onStandClicked()
{
    //qDebug() << "Stand";

    Jogador& jogador = jogo->getJogadores()[0];
    jogador.stand(); // O jogador encerra a jogada
    btnHit->hide();
    btnDouble->hide();

    if (cartaVersoLabel) {
        delete cartaVersoLabel;  // Remove a carta virada
        cartaVersoLabel = nullptr;  // Libera a memória
    }

    //  dealer recebe  cartas  17 ou mais
    jogo->getDealer().jogadaDealer(jogo->getBaralho());  // Dealer compra cartas

    // Exibe as cartas do dealer após a jogada
    exibirCartasDealer(jogo->getDealer().getMao().getCartas(), 330, 172);

    // Após o dealer jogar, você pode verificar a pontuação e terminar o jogo, se necessário
    int pontuacaoDealer = jogo->getDealer().calcularPontuacao();
    int pontuacaoJogador = jogador.calcularPontuacao();

    // Verifica se o dealer estourou ou quem venceu
    if (pontuacaoDealer > 21) {
        QMessageBox::information(this, "Fim de Jogo", "Casa estourou!");
    } else {
        if (pontuacaoJogador > pontuacaoDealer) {
            QMessageBox::information(this, "Fim de Jogo", "Venceu!");
        } else if (pontuacaoJogador < pontuacaoDealer) {
            QMessageBox::information(this, "Fim de Jogo", "Casa venceu!");
        } else {
            QMessageBox::information(this, "Fim de Jogo", "Empate!");
        }
    }
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

void MainWindow::exibirCartasMao(std::vector<Carta>& mao, int xInicial, int y) {
    if (mao.empty()) {
        qDebug() << "A mão do jogador está vazia!";
        return;
    }

    // Limpa cartas anteriores para evitar sobreposição
    for (QLabel* label : cartasLabels) {
        delete label;  // Remove os QLabel antigos antes de criar novos
    }
    cartasLabels.clear();

    // Criando e armazenando QLabel para cada carta
    for (size_t i = 0; i < mao.size(); ++i) {
        QString caminhoCarta = ":/Imgs/Imagens/" + QString::fromStdString(mao[i].getNaipe()) + QString::number(mao[i].getValor()) + ".png";

        QLabel* cartaLabel = new QLabel(this);
        QPixmap cartaPixmap(caminhoCarta);

        cartaLabel->setPixmap(cartaPixmap);
        cartaLabel->setGeometry(xInicial + (i * 70), y, 80, 100);
        cartaLabel->setScaledContents(true);
        cartaLabel->show();
        cartaLabel->raise();  // Garante que está sobre a mesa

        qDebug() << "Imagem carregada com sucesso: " << caminhoCarta;

        cartasLabels.push_back(cartaLabel);  // Armazena o QLabel
    }


}


void MainWindow::exibirCartaVerso(int x, int y) {
    if (cartaVersoLabel) {
        // Se já existe, não adiciona novamente
        return;
    }

    // Exibe o verso da carta do dealer
    QString caminhoVerso = ":/Imgs/Imagens/verso.png";  // Caminho para a imagem do verso da carta
    cartaVersoLabel = new QLabel(this); // Cria o QLabel somente uma vez
    QPixmap cartaPixmap(caminhoVerso);
    cartaVersoLabel->setPixmap(cartaPixmap);
    cartaVersoLabel->setGeometry(x, y, 60, 80);  // Defina a posição e o tamanho do verso da carta
    cartaVersoLabel->setScaledContents(true);  // Ajusta o tamanho da imagem à área do QLabel
    cartaVersoLabel->show();  // Exibe a carta
}

void MainWindow::exibirCartasDealer1(std::vector<Carta>& mao, int xInicial, int y) {
    if (mao.empty()) {
        qDebug() << "A mão do dealer está vazia!";
        return;
    }

    // Limpa cartas anteriores do dealer para evitar sobreposição
    for (QLabel* label : dealerCartasLabels) {
        delete label;
    }
    dealerCartasLabels.clear();

    // Criando e armazenando QLabel para cada carta do dealer
    for (size_t i = 0; i < 1; ++i) {
        QString caminhoCarta = ":/Imgs/Imagens/" + QString::fromStdString(mao[i].getNaipe()) + QString::number(mao[i].getValor()) + ".png";

        QLabel* cartaLabel = new QLabel(this);
        QPixmap cartaPixmap(caminhoCarta);

        cartaLabel->setPixmap(cartaPixmap);
        cartaLabel->setGeometry(xInicial + (i * 70), y, 70, 90); // Posiciona as cartas do dealer
        cartaLabel->setScaledContents(true);
        cartaLabel->show();
        cartaLabel->raise();

        qDebug() << "Carta do dealer exibida: " << caminhoCarta;

        dealerCartasLabels.push_back(cartaLabel); // Armazena o QLabel
    }
}



void MainWindow::exibirCartasDealer(std::vector<Carta>& mao, int xInicial, int y) {

    // Limpa cartas antes do dealer
    for (QLabel* label : dealerCartasLabels) {
        delete label;
    }
    dealerCartasLabels.clear();

    // Criando e armazenando QLabel para cada carta do dealer
    for (size_t i = 0; i < mao.size(); ++i) {
        QString caminhoCarta = ":/Imgs/Imagens/" + QString::fromStdString(mao[i].getNaipe()) + QString::number(mao[i].getValor()) + ".png";

        QLabel* cartaLabel = new QLabel(this);
        QPixmap cartaPixmap(caminhoCarta);

        cartaLabel->setPixmap(cartaPixmap);
        cartaLabel->setGeometry(xInicial + (i * 70), y, 70, 90); // Posiciona as cartas do dealer
        cartaLabel->setScaledContents(true);
        cartaLabel->show();
        cartaLabel->raise();

        qDebug() << "Carta do dealer exibida: " << caminhoCarta;

        dealerCartasLabels.push_back(cartaLabel); // Armazena o QLabel
    }
}

void MainWindow::onReiniciarClicked()
{
    // Limpa as mãos
    jogo->getJogadores()[0].limparMao();
    jogo->getDealer().limparMao();

    // Reinicia a partida
    jogo->distribuirCartas();

    // Atualiza as cartas
    exibirCartasMao(jogo->getJogadores()[0].getMao().getCartas(), 350, 300);
    exibirCartasDealer1(jogo->getDealer().getMao().getCartas(), 330, 172);


    updateSaldo();
    exibirCartaVerso(420, 180);
    btnHit->show();
    btnDouble->show();
    jogo->getJogadores()[0].setAtivo(true);  //  jogador ativo novamente
}
