/* 2021 - Emmanuel Duarte Claudino 
   License: GPL v3
*/

#include <stdio.h>

/*função para verificar a vitoria pela igualdade dos simbolos (X ou O) pelas determinadas funções e
  o possivel empate pelo numero de jogadas ate o momento da verificação
*/
int verificarVitoria(char tabela [3][3], char simbolo, int numeroJogadas){
   for (register int i = 0; i <3; i++){
         if ((tabela [i][0]) == (tabela [i][1]) && (tabela [i][0]) == (tabela [i][2])){
            printf(" O jogador que utilizou o simbolo %c ganhou!!!!\n\n", simbolo);
            return 0;
        }
   }
   for (register int j = 0; j <3; j++){
         if ((tabela [0][j]) == (tabela [1][j]) && (tabela [0][j]) == (tabela [2][j])){
            printf(" O jogador que utilizou o simbolo %c ganhou!!!!\n\n", simbolo);
            return 0;
        }
   }
   if ((tabela [0][0]) == (tabela [1][1]) && (tabela [0][0]) == (tabela [2][2])){
        printf(" O jogador que utilizou o simbolo %c ganhou!!!!\n\n", simbolo);
        return 0;
   } else if ((tabela [0][2]) == (tabela [1][1]) && (tabela [0][2]) == (tabela [2][0])){
        printf(" O jogador que utilizou o simbolo %c ganhou!!!!\n\n", simbolo);
        return 0;
   } else if (numeroJogadas == 9){
        printf(" A partida deu velha(empatou) :(\n\n");
        return 0;        
   }
}

int verificarPosicao (char posicao){
    if ((posicao == 'X') || (posicao == 'O')){
        printf("\n A posicao que voce quer jogar ja esta ocupada!\n");
        return 0;
    }else{
        return 1;
    }
}

// apresenta ao usuario o estado atual da tabela
void mostrarTabela (char tabela[3][3]){
    for (register int i = 0; i < 3; i++){
        for (register int j = 0; j < 3; j++){
            printf(" | %c | ", tabela[i][j]);
        }
        printf("\n");
    }
}

int main (){
    char tabela [3][3];
    int jogando = 1;
    int jogou = 0;
    int numeroJogadas = 0;
    int condicionalPosicao = 0;
    char simbolo = 'X';
    char posicao;
    
    for (register int i = 0; i < 3; i++){
        if ( i == 0){
            condicionalPosicao = 7;
        } else if (i == 1){
            condicionalPosicao = 8;
        }else if ( i == 2){
            condicionalPosicao = 9;
        }
        for (register int j = 0; j < 3; j++, condicionalPosicao -= 3){
            tabela [i][j] = condicionalPosicao+'0';
        }  
    } 
    printf(" Jogo da velha 1.1v \n Emmanuel Duarte Claudino - GPL3\n\n");
    while (jogando){
        mostrarTabela(tabela);
        printf("\n Qual posicao voce quer jogar? ");
        scanf("%c", &posicao);
        printf("\n");
        while ((getchar()) != '\n'); //buffer cleaning
        switch (posicao){  
            case '1':
               if (verificarPosicao(tabela [0][2])){
                tabela [0][2] = simbolo;
                jogou = 1;
                }
                break;
            case '2':
               if (verificarPosicao(tabela [1][2])){
                tabela [1][2] = simbolo;
                jogou = 1;
               }
               break;
            case '3':
               if (verificarPosicao(tabela [2][2])) {
                tabela [2][2] = simbolo;
                jogou = 1;
               }
               break;
            case '4':
               if (verificarPosicao(tabela [0][1])){
                tabela [0][1] = simbolo;
                jogou = 1;
               } 
               break;
            case '5':
               if (verificarPosicao(tabela [1][1])){
                tabela [1][1] = simbolo;
                jogou = 1;
               }
               break;
            case '6':
               if (verificarPosicao(tabela [2][1])){
                tabela [2][1] = simbolo;
                jogou = 1;
               } 
               break;
            case '7':
               if (verificarPosicao(tabela [0][0])){
                tabela [0][0] = simbolo;
                jogou = 1;
               }
               break;
            case '8':
               if (verificarPosicao(tabela [1][0])){
                tabela [1][0] = simbolo;
                jogou = 1;
               }
               break;
            case '9':
               if (verificarPosicao(tabela [2][0])){
                tabela [2][0] = simbolo;
                jogou = 1;
               }
               break;   
            default:
                printf("A posicao %c nao existe ou esta incorreta, tente novamente\n\n", posicao);
                break;
            }
        if (jogou){
            jogou = 0;
            ++numeroJogadas;
            jogando = verificarVitoria(tabela, simbolo, numeroJogadas);
            if ( simbolo == 'X' ){
                simbolo = 'O';
            }else{
                simbolo = 'X';
            }
        }
    }
    mostrarTabela(tabela);
}
/* 2021 - Emmanuel Duarte Claudino 
   License: GPL v3
*/
