#ifndef IO_H
#define IO_H

#include "jogo.h"

void ler_configuracao(const char *filename);
void mostrar_menu_principal();
void mostrar_menu_jogo(Jogo_whot *jogo);
void exibir_cartas(Jogador_whot *jogador);
void exibir_estado_jogo(Jogo_whot *jogo);

#endif
