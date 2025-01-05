#include "io.h"
#include <stdio.h>

void ler_configuracao(const char *filename) {
    // Função de configuração inicial (a ser implementada conforme a necessidade)
    printf("Carregando configuração do arquivo %s...\n", filename);
}

void mostrar_menu_principal() {
    printf("1. Iniciar novo jogo\n");
    printf("2. Visualizar jogos realizados\n");
    printf("3. Ver estatísticas de grupos de jogos\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

void mostrar_menu_jogo(Jogo_whot *jogo) {
    printf("1. Mostrar cartas dos jogadores\n");
    printf("2. Iniciar jogada\n");
    printf("3. Mostrar estado do jogo\n");
    printf("4. Terminar jogo\n");
    printf("Escolha uma opção: ");
}
