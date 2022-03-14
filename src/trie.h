/*
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 */
#ifndef TRIE_H
#define TRIE_H

typedef struct trie
{
    char eh_raiz;
    char letra;
    unsigned indice_letra;
    struct trie **prox;
    unsigned int mprox;
} trie;

trie *trie_inic();
void trie_preenche(trie *raiz, char *letra);

#define MAXFILHOS(m) 2 * m
#define MAXCHAVES(m) MAXFILHOS(m) - 1

#endif


