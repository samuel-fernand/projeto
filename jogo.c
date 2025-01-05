#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void baralhar_baralho(Jogo_whot *jogo) {
    for (int i = NUM_CARTAS - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // Gera um índice aleatório entre 0 e i
        Carta temp = jogo->baralho[i];
        jogo->baralho[i] = jogo->baralho[j];
        jogo->baralho[j] = temp;
    }
}

void distribuir_cartas(Jogo_whot *jogo) {
    int carta_count = 0;
    for (int i = 0; i < jogo->num_jogadores; i++) {
        for (int j = 0; j < MAX_CARTAS; j++) {
            jogo->jogadores[i].mao[j] = jogo->baralho[carta_count++];
        }
        jogo->jogadores[i].num_cartas = MAX_CARTAS;  // Cada jogador começa com 6 cartas
    }
}

bool jogada_valida(Carta carta_jogada, Carta call_card) {
    if (carta_jogada.is_whot) return true;  // Carta Whot pode ser jogada sempre
    return carta_jogada.numero == call_card.numero || carta_jogada.naipe == call_card.naipe;
}

void realizar_jogada(Jogador_whot *jogador, int indice_carta, Carta *call_card, Jogo_whot *jogo) {
    Carta carta_jogada = jogador->mao[indice_carta];
    if (jogada_valida(carta_jogada, *call_card)) {
        *call_card = carta_jogada;
        for (int i = indice_carta; i < jogador->num_cartas - 1; i++) {
            jogador->mao[i] = jogador->mao[i + 1];
        }
        jogador->num_cartas--;
        jogo->cartas_jogadas[jogo->num_cartas_baralho++] = carta_jogada;
    } else {
        printf("Jogada inválida!\n");
    }
}

void game_loop(Jogo_whot *jogo) {
    int turno = 0;
    while (1) {
        Jogador_whot *jogador_atual = &jogo->jogadores[turno];

        // Exibe o estado atual do jogo
        exibir_estado_jogo(jogo);

        // Exibe as cartas do jogador atual
        exibir_cartas(jogador_atual);

        // Solicita a jogada
        int carta_index;
        printf("Escolha uma carta para jogar (0 a %d): ", jogador_atual->num_cartas - 1);
        scanf("%d", &carta_index);

        if (carta_index >= 0 && carta_index < jogador_atual->num_cartas) {
            realizar_jogada(jogador_atual, carta_index, &jogo->call_card, jogo);
        }

        // Verifica se o jogador venceu (ficou sem cartas)
        if (jogador_atual->num_cartas == 0) {
            printf("Jogador %s venceu!\n", jogador_atual->nome);
            break;
        }

        // Passa para o próximo jogador
        turno = (turno + 1) % jogo->num_jogadores;
    }
}


void exibir_cartas(Jogador_whot *jogador) {
    printf("Cartas de %s:\n", jogador->nome);
    for (int i = 0; i < jogador->num_cartas; i++) {
        printf("Carta %d: %d %d\n", i, jogador->mao[i].naipe, jogador->mao[i].numero);
    }
}

void exibir_estado_jogo(Jogo_whot *jogo) {
    printf("Carta de chamada: %d %d\n", jogo->call_card.naipe, jogo->call_card.numero);
    printf("Cartas já jogadas: \n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        if (jogo->cartas_jogadas[i].numero != 0) {
            printf("%d %d ", jogo->cartas_jogadas[i].naipe, jogo->cartas_jogadas[i].numero);
        }
    }
    printf("\n");
}


void inicializar_jogo(Jogo_whot *jogo) {
    srand(time(NULL));  // Inicializa a semente com o tempo atual

    printf("Digite o número de jogadores (2 a 4): ");
    scanf("%d", &jogo->num_jogadores);

    for (int i = 0; i < jogo->num_jogadores; i++) {
        printf("Digite o nome do jogador %d: ", i + 1);
        scanf("%s", jogo->jogadores[i].nome);
        printf("Digite o username do jogador %d: ", i + 1);
        scanf("%s", jogo->jogadores[i].username);
        jogo->jogadores[i].num_cartas = MAX_CARTAS;  // Distribui 6 cartas iniciais
    }

    // Baralha as cartas e distribui para os jogadores
    baralhar_baralho(jogo);
    distribuir_cartas(jogo);

    // Escolhe a call card aleatória
    jogo->call_card = jogo->baralho[0]; // Escolhe a primeira carta como exemplo
    printf("A carta de chamada é: %d %d\n", jogo->call_card.naipe, jogo->call_card.numero);
}
