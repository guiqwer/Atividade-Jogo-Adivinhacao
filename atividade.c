/*
1) Hoje o jogo escolhe um número entre 0 e 99. Deixe o usuário  escolher esse limite. Você precisa capturar esses dois números dele,  e usá-los na hora de calcular o número randômico.

2) Temos ainda alguns números mágicos em nosso código. Use  #defines para a quantidade de tentativas por níveis.

3) Ao terminar uma partida, pergunte para o usuário se ele quer jogar  novamente. Se ele digitar “1”, significa que quer, então você deverá  começar o jogo de novo. Para isso, você precisará usar mais um loop.

4) Não deixe o usuário jogar o mesmo número na sequência. Se ele  jogou o número “2”, errou, e jogou novamente o “2”, avise-o de que ele  já jogou esse número, e não conte como uma tentativa. Para isso, crie  uma variável que guardará o “último número chutado”. (Não tente  guardar todos os números chutados nesse momento. Aprenderemos  como fazer isso mais para frente.

*/
// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definindo as constantes
#define numeroDeTentativasFacil 20
#define numeroDeTentativasMedio 15
#define numeroDeTentativasDificil 6

int main()
{
  int jogarNovamente;
  int ultimoChute = 0;

  do
  {
    // imprimindo cabecalho bonito do jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    // declarando variaveis
    int chute;
    int acertou;
    int nivel;
    int totaldetentativas;
    int valorMinimo, valorMaximo;

    // solicitando os números para calcular o número ramdômico
    printf("Dígite o valor mínimo para o número secreto:\n");

    scanf("%d", &valorMinimo);

    printf("Digite o valor máximo para o número secreto:\n");

    scanf("%d", &valorMaximo);

    // definindo a quantidade de pontos inicial
    double pontos = 1000;

    // gerando um numero secreto aleatorio
    srand(time(0));
    int numerosecreto = rand() % (valorMaximo - valorMinimo + 1) + valorMinimo;
    ;

    // escolhendo o nivel de dificuldade
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");

    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
      totaldetentativas = numeroDeTentativasFacil;
      break;
    case 2:
      totaldetentativas = numeroDeTentativasMedio;
      break;
    default:
      totaldetentativas = numeroDeTentativasDificil;
      break;
    }

    // loop principal do jogo
    for (int i = 1; i <= totaldetentativas; i++)
    {
      printf("Chute um número: ");
      scanf("%d", &chute);

      if (chute == ultimoChute)
      {
        printf("Você já chutou esse número:");
        i--;
      }

      printf("-> Tentativa %d de %d\n", i, totaldetentativas);

      ultimoChute = chute;

      // tratando chute de numero negativo
      if (chute < 0)
      {
        printf("Você não pode chutar números negativos\n");
        i--;
        continue;
      }

      // verifica se acertou, foi maior ou menor
      acertou = chute == numerosecreto;

      if (acertou)
      {
        break;
      }
      else if (chute > numerosecreto)
      {
        printf("\nSeu chute foi maior do que o número secreto!\n\n");
      }
      else
      {
        printf("\nSeu chute foi menor do que o número secreto!\n\n");
      }

      // calcula a quantidade de pontos
      double pontosperdidos = abs(chute - numerosecreto) / 2.0;
      pontos = pontos - pontosperdidos;
    }

    // imprimindo mensagem de vitoria ou derrota
    printf("\n");
    if (acertou)
    {
      printf("             OOOOOOOOOOO               \n");
      printf("         OOOOOOOOOOOOOOOOOOO           \n");
      printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
      printf("    OOOOOO      OOOOO      OOOOOO      \n");
      printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
      printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
      printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
      printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
      printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
      printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
      printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
      printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
      printf("         OOOOOO         OOOOOO         \n");
      printf("             OOOOOOOOOOOO              \n");
      printf("\nParabéns! Você acertou!\n");
      printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
    }
    else
    {

      printf("       \\|/ ____ \\|/    \n");
      printf("        @~/ ,. \\~@      \n");
      printf("       /_( \\__/ )_\\    \n");
      printf("          \\__U_/        \n");

      printf("\nVocê perdeu! Tente novamente!\n\n");
    }

    printf("Você deseja jogar novamente?\n (1) Jogar Novamente \n (0) Sair");
    scanf("%d", &jogarNovamente);

  } while (jogarNovamente == 1);
}