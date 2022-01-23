#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

const Player1 = 'X';
const Player2 = 'O';

char jogada[3][3] = {0}, nomePlayer1[20] = {0},nomePlayer2[20] = {0};
int linha = 0, coluna = 0, numerodeJogadas = 0, vezdoPlayer = 0;

void definirNome();
void mostrarTabuleiro();
void jogar();
int verificarJogada();
int verificarLinhas();
int verificarColunas();
int verificarDiagonais();
void jogadaInvalida();

int main(){
    printf("\n--------JOGO DA VELHA--------\n");
    definirNome();
    while(numerodeJogadas <= 9){
        mostrarTabuleiro();
        if(vezdoPlayer % 2 == 0){
            printf("\nVez do(a) %s:\n",nomePlayer1);
            jogar();
            vezdoPlayer++;
            numerodeJogadas++;
            if(verificarJogada() == 1){
                jogada[linha - 1][coluna - 1] = Player1;
            }
            if(verificarLinhas() || verificarColunas() || verificarDiagonais()){
                system("cls");
                printf("\n--------JOGO DA VELHA--------\n");
                printf("\n\t%s venceu!\n",nomePlayer1);
                break;
            } else if(numerodeJogadas == 9 && verificarLinhas() == 0 && verificarColunas() == 0 && verificarDiagonais() == 0){
                system("cls");
                printf("\n--------JOGO DA VELHA--------\n");
                printf("\n\tEmpate!\n");
                break;
            }
        }else if(vezdoPlayer % 2 == 1){ 
            printf("\nVez do(a) %s:\n",nomePlayer2);
            jogar();
            ++vezdoPlayer;
            ++numerodeJogadas;
            if(verificarJogada()) jogada[linha -  1][coluna - 1] = Player2;
            if(verificarLinhas() || verificarColunas() || verificarDiagonais()){
                system("cls");
                printf("\n--------JOGO DA VELHA--------\n");
                printf("\n\t%s venceu!\n",nomePlayer2);
                break;
            } else if(numerodeJogadas == 9 && verificarLinhas() == 0 && verificarColunas() == 0 && verificarDiagonais() == 0){
                system("cls");
                printf("\n--------JOGO DA VELHA--------\n");
                printf("\n\tEmpate!\n");
                break;
            }
        }
    }
    system("pause");
    return 0;
}

void definirNome(){
    printf("\nDigite o nome do(a) Player1: ");
    scanf(" %[^\n]",nomePlayer1);
    printf("Digite o nome do(a) Player2: ");
    scanf(" %[^\n]",nomePlayer2);
    system("cls");
}

void mostrarTabuleiro(){
    system("cls");
    printf("\n--------JOGO DA VELHA--------\n");
    printf("\n\t %s x %s\n",nomePlayer1,nomePlayer2);
    printf("\n\t   %c | %c | %c\n",jogada[0][0],jogada[0][1],jogada[0][2]);
    printf("\t------------\n");
    printf("\t   %c | %c | %c\n",jogada[1][0],jogada[1][1],jogada[1][2]);
    printf("\t------------\n");
    printf("\t   %c | %c | %c\n",jogada[2][0],jogada[2][1],jogada[2][2]);
    return;
}

void jogar(){
    printf("\nLinha: ");
    scanf("%d",&linha);
    printf("Coluna: ");
    scanf("%d",&coluna);
    return;
}

int verificarJogada(){
    if(linha > 0 && linha <= 3 && coluna > 0 && coluna <= 3){
        if(jogada[linha - 1][coluna - 1] == Player1 || jogada[linha - 1][coluna - 1] == Player2){
            jogadaInvalida();
            return 0; 
        }
        return 1;
    }
    jogadaInvalida();
    return 0;
}
int verificarLinhas(){
    if(jogada[0][0] == Player1 && jogada[0][1] == Player1 && jogada[0][2] == Player1) return 1;
    if(jogada[1][0] == Player1 && jogada[1][1] == Player1 && jogada[1][2] == Player1) return 1;
    if(jogada[2][0] == Player1 && jogada[2][1] == Player1 && jogada[2][2] == Player1)
    return 1;
    if(jogada[0][0] == Player2 && jogada[0][1] == Player2 && jogada[0][2] == Player2) return 1;
    if(jogada[1][0] == Player2 && jogada[1][1] == Player2 && jogada[1][2] == Player2) return 1;
    if(jogada[2][0] == Player2 && jogada[2][1] == Player2 && jogada[2][2] == Player2)
    return 1;
    return 0;
}
int verificarColunas(){
    if(jogada[0][0] == Player1 && jogada[1][0] == Player1 && jogada[2][0] == Player1) return 1;
    if(jogada[0][1] == Player1 && jogada[1][1] == Player1 && jogada[2][1] == Player1) return 1;
    if(jogada[0][2] == Player1 && jogada[1][2] == Player1 && jogada[2][2] == Player1) return 1;
    if(jogada[0][0] == Player2 && jogada[1][0] == Player2 && jogada[2][0] == Player2) return 1;
    if(jogada[0][1] == Player2 && jogada[1][1] == Player2 && jogada[2][1] == Player2) return 1;
    if(jogada[0][2] == Player2 && jogada[1][2] == Player2 && jogada[2][2] == Player2) return 1;
    return 0;
}
int verificarDiagonais(){
    if(jogada[0][0] == Player1 && jogada[1][1] == Player1 && jogada[2][2] == Player1) return 1;
    if(jogada[0][2] == Player1 && jogada[1][1] == Player1 && jogada[2][0] == Player1) return 1;
    if(jogada[0][0] == Player2 && jogada[1][1] == Player2 && jogada[2][2] == Player2) return 1;
    if(jogada[0][2] == Player2 && jogada[1][1] == Player2 && jogada[2][0] == Player2) return 1;
    return 0;
}

void jogadaInvalida(){
    --vezdoPlayer;
    --numerodeJogadas;
    printf("\n[Erro] Jogada nao-permitida!");
    printf("\nTente Novamente...\n");
    Sleep(1000);
    return;
}