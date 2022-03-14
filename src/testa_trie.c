/*
 * aluno: joilnen leite, daniel morais, matheus silva
 */

/**
 * inclusao da bilioteca implementada baseada em arvores red black
 */
#include <stdio.h>
#include <string.h>

#include "jcurses.h"
#include "testa_bm.h"

void tela_testa_bm()
{
    int li = 8, co = 24, f;
    char mens[7][49] =
    {
        S_UNDERL"serah efetuado os testes:"S_NORM,
        "",
        "insercao e remocao na arvore",
        "nao foi pedido mas me ajudou a",
        "checar a correcao da arvore",
        "cada simbolo da base reprensenta",
        "paginas folhas ou multiplos delas"
    };
    LTELA;
    for (f = 0; f < 7; f++)
        CKLSITEM(li++, co, 0, mens[f]);
    INFO_FILE(__FILE__);
    CMR1;
}

/**
 * funcao main de teste separada do codigo da biblioteca como especificado
 */
void testa_arvore_bm()
{
    int i = 20;
    char temp[20];
    while (i)
    {
        LTELA;
        /** PNAPOS(20, 39, S_VERMB, S_BRANCO, S_TEST"A"); */
        /** PNAPOS(20, 39, S_PRETO, S_PISCA, S_PRETO"A"S_NORM); */
        sprintf(temp, "ad. %dpg", 21 - i);
        INFO(temp);
        CMR1;
        i--;
    }
}



