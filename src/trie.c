/*
 * Grupo 11
 * alunos: joilnen leite, daniel morais, matheus silva
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bm.h"

/**
 * faz a inicialização da arvore b+
 * @param int i ordem da arvore
 */
bm *bm_inic(int i)
{
    bm *b = (bm *)malloc(sizeof(bm));
    b->raiz = NULL;
    b->mgrau = i;

    return b;
}

/**
 * faz a impressão da arvore b+
 * @param bm b arvore
 */
void bm_escrutina(bm *b)
{
    if (b->raiz)
        bm_noh_escrutina(b->raiz, 0);
}

/**
 * faz a pesquisa de uma chave na arvore b+
 * @param bm b arvore
 * @param int chave a ser buscada
 */
bm_noh *bm_pesquisa(bm *b, int chave)
{
    return (b->raiz) ? bm_noh_pesquisa(b->raiz, chave) : NULL;
}

static void bm_grava_art(bm_noh *raiz, int chave, s_artigo *art)
{
    int i;
    for (i = 0; i < raiz->nchaves; i++)
    {
        if (raiz->chaves[i] == chave)
        {
            art->id = chave;
            bm_noh_escrevedisc(raiz, art);
        }
    }
}

void bm_lista(bm_noh *aux, int chave)
{
    int i;

    if (!aux)
        return;

    if (aux->eh_folha)
    {
        printf("->");
        for (int j = 0; j < aux->nchaves; j++)
            printf(" %d ", aux->chaves[j]);
    }
    else
    {
        int i = 0, j = 0;
        while (j <= aux->nchaves)
        {
            if (aux->chaves[i] < chave){
                i++;
                j++;
            }
            else {
                bm_lista(aux->filhos[j], chave);
                j++;
            }
        }
    }
}

/**
 * faz a inserção de uma chave na folha da arvore b+
 * @param bm b arvore
 * @param int chave a ser buscada
 * @param s_artigo art artigo a ser armazenado
 */
bm_noh *bm_insere_nahfolha(bm_noh *raiz, int chave, s_artigo *art)
{
    int i;
    if (!raiz->eh_folha)
    {
        for (i = raiz->nchaves - 1; i >= 0; --i)
        {
            if (raiz->chaves[i] < chave)
            {
                bm_insere_nahfolha(raiz->filhos[i + 1], chave, art);
                i = -1;
            }
        }
    }
    else
    {
        bm_noh_insere(raiz, chave);
        if (raiz->nchaves == MAXCHAVES(raiz->mgrau) + 1)
        {
            if (!raiz->pai)
            {
                bm_noh *aux = bm_noh_inic(raiz->mgrau, 0);
                aux->filhos[0] = raiz;
                raiz->pai = aux;
                i = 0;
            }
            else
            {
                i = raiz->pai->nchaves;
                while (i >= 0 && raiz->pai->chaves[i] > chave)
                {
                    raiz->chaves[i + 1] = raiz->chaves[i];
                    --i;
                }
            }
            bm_noh_split(raiz->pai, raiz, i);
        }

        bm_grava_art(raiz, chave, art);
    }

    while (raiz->pai)
        raiz = raiz->pai;

    return raiz;
}

void bm_geraarvore(bm *bm)
{
    FILE *parq;
    int j, i;
    long pos_arq;
    int quantos_arts = 0;

    char *tmp;

    tmp = (char *)malloc(sizeof(char) * (strlen(NOME_ARQ) + strlen(SUFIXO_BM) + 1));
    strcpy(tmp, NOME_ARQ""SUFIXO_BM);

    if (!(parq = fopen(tmp, "r")))
    {
        free(tmp);
        return;
    }
    free(tmp);
    rewind(parq);
    fread(&quantos_arts, sizeof(int), 1, parq);
    rewind(parq);
    fseek(parq, sizeof(int), SEEK_END);

    for (j = 0; j < quantos_arts; j++)
    {
        s_artigo *a = (s_artigo *)malloc(sizeof(s_artigo));
        pos_arq = ftell(parq);
        fread(a, sizeof(s_artigo), 1, parq);
        bm_noh *noh = bm_pesquisa(bm, a->id);
        if (noh)
        {
            for (i = 0; i < noh->nchaves; i++)
            {
                if (noh->chaves[i] == a->id)
                    *(noh->dfilhos[i]) = pos_arq;
            }
        }
        free(a);
    }
    fclose(parq);
}

/**
 * faz a inserção de uma chave na arvore b+
 * @param bm b arvore
 * @param int chave a ser buscada
 * @param s_artigo art artigo a ser armazenado
 */
void bm_insere(bm *b, int chave, s_artigo *art)
{
    /** se arvore vazia */
    if (b->raiz)
    {
        if (bm_noh_pesquisa_folha(b->raiz, chave))
        {
            printf("\nChave ja inserida na arvore\n");
            return;
        }
        // bm_escrutina(b);
        b->raiz = bm_insere_nahfolha(b->raiz, chave, art);
    }
    else /** se arvore nchaves vazia */
    {
        /** aloca memoria para noh raiz */
        b->raiz = bm_noh_inic(b->mgrau, 1);
        b->raiz->nchaves = 1;       /** atualiza o numero de chaves */
        b->raiz->chaves[0] = chave; /** insere chave */
        bm_grava_art(b->raiz, chave, art);
    }
}


