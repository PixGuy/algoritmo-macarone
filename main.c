#include <stdio.h>
#include <string.h>

const char ASCII_PRINTABLE_MIN = 'A';
const char ASCII_PRINTABLE_MAX = 'Z';

const int TAMANHO_SENHA = 7;
const char* SENHA = "ASBOLAS";

int completado = 0;
int t = 1;
void tentar_quebrar(char tentativa[TAMANHO_SENHA]) {

    if (strcmp(tentativa, SENHA) == 0) {
        printf("A senha foi quebrada!\n");
        completado = 1;
    }

    if (strlen(tentativa) > TAMANHO_SENHA) return;

    for (char i = ASCII_PRINTABLE_MIN; i < ASCII_PRINTABLE_MAX; i++) {
        if (completado) return;
        t += 1;
        char nova_tentativa[TAMANHO_SENHA];
        strcpy(nova_tentativa, tentativa);
        int empty_place = strlen(nova_tentativa);
        if (empty_place > TAMANHO_SENHA) return;
        nova_tentativa[empty_place] = i;
        nova_tentativa[empty_place + 1] = '\0';
        printf("Tentando %s contra %s | %i\n", nova_tentativa, SENHA, t);
        tentar_quebrar(nova_tentativa);
    }
}

int main(void) {
   tentar_quebrar("");
}