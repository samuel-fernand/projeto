#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "io.h"
#include "time.h"

int main() {
    Jogo_whot jogo;
    srand(time(NULL));

    // Carregar configurações (se necessário)
    ler_configuracao("config_whot.txt");

    // Inicializar o jogo
    inicializar_jogo(&jogo);

    // Loop de jogo
    game_loop(&jogo);

    // Gerar relatório final
    gerar_relatorio(&jogo);

    return 0;
}
