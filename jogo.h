#ifndef JOGO_H
#include <stdbool.h>

#define MAX_JOGADORES 4
#define NUM_CARTAS 54
#define MAX_CARTAS 6

// Definindo os naipes como enum
typedef enum {
    CIRCULOS, CRUZES, TRIANGULOS, ESTRELAS, QUADRADOS
} Naipe;

typedef struct {
    Naipe naipe;
    int numero;
    bool is_whot;  // Indica se a carta é uma carta Whot (número 20)
} Carta;

// Jogador
typedef struct {
    char nome[50];
    char username[50];
    Carta mao[MAX_CARTAS];  // Cartas do jogador
    int num_cartas;
} Jogador_whot;

// Jogo
typedef struct {
    int id_jogo;
    Jogador_whot jogadores[MAX_JOGADORES];  // Jogadores do jogo
    int num_jogadores;
    Carta baralho[NUM_CARTAS];  // Cartas do baralho
    Carta call_card;  // Carta de chamada
    Carta cartas_jogadas[NUM_CARTAS];  // Cartas já jogadas
    int num_cartas_baralho;
} Jogo_whot;


// Funções
void baralhar_baralho(Jogo_whot *jogo);
void distribuir_cartas(Jogo_whot *jogo);
bool jogada_valida(Carta carta_jogada, Carta call_card);
void realizar_jogada(Jogador_whot *jogador, int indice_carta, Carta *call_card, Jogo_whot *jogo);
void game_loop(Jogo_whot *jogo);
void gerar_relatorio(Jogo_whot *jogo);
void exibir_cartas(Jogador_whot *jogador);
void exibir_estado_jogo(Jogo_whot *jogo);
void inicializar_jogo(Jogo_whot *jogo);
void mostrar_menu_principal();
void mostrar_menu_jogo(Jogo_whot *jogo);

#endif
