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
    char *ptabela = &tabela[0][0];
    int jogando = 1;
    int jogou = 0;
    int numeroJogadas = 0;
    char simbolo = 'X';
    char posicao;
    
    for (register int i = 0; i < 9; i++){
            *(ptabela+i) = i+'0'+1;
    } 
    printf(" Jogo da velha 1.2v Player vs Player \n Emmanuel Duarte Claudino - GPL3\n\n");
    while (jogando){
        mostrarTabela(tabela);
        printf("\n Qual posicao voce quer jogar? ");
        scanf("%c", &posicao);
        printf("\n");
        while ((getchar()) != '\n'); //buffer cleaning
        if(posicao){
            int numeroPosicao = (posicao - '0') - 1;
            if(verificarPosicao(*(ptabela+numeroPosicao))){
                *(ptabela + numeroPosicao) = simbolo;
                jogou = 1;
            }
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