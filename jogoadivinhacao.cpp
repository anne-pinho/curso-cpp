#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main (){
    cout << "*****************************************" << endl;
    cout << "Bem vindos ao Jogo da Adivinhação" << endl;
    cout << "*****************************************" << endl;
    
    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout  << "Fácil (F), Médio (M), ou Difícil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int num_tentativas;

    if (dificuldade == 'F' || dificuldade == 'f') {
        num_tentativas = 15;
    } else if ( dificuldade == 'M' || dificuldade == 'm'){
        num_tentativas = 10;
    } else if (dificuldade == 'D' || dificuldade == 'd'){
        num_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand()%100;
    
    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= num_tentativas; tentativas++){
    
        int chute;

        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;

        cout << "o valor do seu chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou){
            cout << "Parabéns, você acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        } else if (maior){
            cout << "Seu chute foi maior que o numero secreto" << endl;
        } else {
            cout << "Seu chute foi menor que o numero secreto" << endl;
        }      
    }
    
    cout << "Fim de jogo!" << endl;

    if (nao_acertou){
        cout << "Você perdeu! Tente novamente." << endl;
    } else {
        cout << "Voce acertou em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos" << endl;
    }
 
}