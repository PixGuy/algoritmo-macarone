/*
    "diabólico."
    -- Mauro Lopes de Almeida Junior, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char ASCII_PRINTABLE_MIN = '!';
const char ASCII_PRINTABLE_MAX = '~';

const int TAMANHO_SENHA = 7; /* técnicamente, o tamanho do buffer */

const char* SEED = "Sgt._Pepper's_Lonely_Hearts_Club_Band";

int completado = 0;
int tentativas = 1;

void
tentar_quebrar(char tentativa[TAMANHO_SENHA], char* senha) {

    if (strcmp(tentativa, senha) == 0) {
        printf("A senha foi quebrada!\n");
        completado = 1;
        return;
    }
    
    int empty_place = strlen(tentativa);
    if (empty_place >= TAMANHO_SENHA - 1) return;

    for (int i = ASCII_PRINTABLE_MIN; i <= ASCII_PRINTABLE_MAX; i++) {
        if (completado) return;
        char nova_tentativa[TAMANHO_SENHA];
        strcpy(nova_tentativa, tentativa);
        nova_tentativa[empty_place] = (char)i;
        nova_tentativa[empty_place + 1] = '\0';
        printf("Testando %s contra %s | %i\n", nova_tentativa, senha, tentativas);
        tentativas ++;
        tentar_quebrar(nova_tentativa, senha);
    }
}

void
gerar_senha(char senha[TAMANHO_SENHA]) {
    srand(time(NULL));
    int n = strlen(SEED)/sizeof(SEED[0]);

    for (int i = 0; i < TAMANHO_SENHA - 1; i++) {
        senha[i] = SEED[rand() % n];
    }
    senha[TAMANHO_SENHA - 1] = '\0';
}

int 
main(void) {
    char senha[TAMANHO_SENHA];
    gerar_senha(senha);
    tentar_quebrar("", senha);
}