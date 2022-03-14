/* Grupo 11
 * alunos: joilnen leite, daniel morais, matheus silva
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bm_noh.h"
#include "erro.h"

/**
 * faz a inicialização de um nó
 * @param int i grau da página
 * @param char eh_folha flag para saber se a página é interna ou externa
 *
 */
bm_noh *bm_noh_inic(int i, char eh_folha)
{
    bm_noh *n = (bm_noh *)malloc(sizeof(bm_noh));
    n->mgrau = i;
    n->chaves = (int *)malloc(sizeof(int) * MAXCHAVES(n->mgrau));
    n->filhos = (bm_noh **)malloc(sizeof(bm_noh) * MAXFILHOS(n->mgrau));
    n->dfilhos = (long **)malloc(sizeof(long) * MAXCHAVES(n->mgrau));
    n->pai = NULL;

    n->nchaves = 0;
    n->eh_folha = eh_folha;
    return n;
}

/**
 * realiza a partição de uma página folha
 * @param bm_noh bmn
 * @param bm_noh y
 * @param int i 
 */
void bm_noh_split(bm_noh *bmn, bm_noh *y, int i)
{
    int j;
    printf("\nbm_noh_split\n");
    bm_noh *z = bm_noh_inic(y->mgrau, y->eh_folha);
    z->pai = bmn;
    y->pai = bmn;
    //Como z é sempre um noh folha, ele tambem recebe os ponteiros de arquivo de y
    for (j = 0; j < bmn->mgrau; j++)
    {
        z->chaves[j] = y->chaves[j + bmn->mgrau];
        z->dfilhos[j] = y->dfilhos[j + bmn->mgrau];
        z->nchaves++;
    }
    y->nchaves -= z->nchaves;

    for (j = bmn->nchaves; j >= i + 1; j--){
        bmn->filhos[j + 1] = bmn->filhos[j];
        bmn->dfilhos[j] = bmn->dfilhos[j-1];
    }
    bmn->filhos[i + 1] = z;
    for (j = bmn->nchaves - 1; j >= i; j--)
        bmn->chaves[j + 1] = bmn->chaves[j];

    for (j = bmn->nchaves - 1; j >= i; j--)
        bmn->chaves[j + 1] = bmn->chaves[j];

    bmn->chaves[i] = y->chaves[bmn->mgrau];
    bmn->nchaves++;
    bmn = bm_noh_split_int(bmn, y, z);
}


/**
 * realiza a partição de uma página interna
 * @param bm_noh bmn
 * @param bm_noh y
 * @param int i 
 */
bm_noh *bm_noh_split_int(bm_noh *bmn, bm_noh *y, bm_noh *z)
{
    int j;
    if (bmn->nchaves == MAXCHAVES(bmn->mgrau) + 1)
    {
        bm_noh *w = bm_noh_inic(bmn->mgrau, 0);
        for (j = 1; j < bmn->mgrau; j++)
        {
            w->chaves[j - 1] = bmn->chaves[j + bmn->mgrau];
            w->dfilhos[j - 1] = bmn->dfilhos[j + bmn->mgrau];
            w->filhos[j - 1] = bmn->filhos[j + bmn->mgrau];
            w->filhos[j] = bmn->filhos[j + bmn->mgrau + 1];
            w->nchaves++;
            bmn->nchaves--;
        }
        bmn->nchaves--;

        bm_noh *noh_novo;
        if (!bmn->pai)
        {
            noh_novo = bm_noh_inic(bmn->mgrau, 0);
            bmn->pai = noh_novo;
            noh_novo->chaves[0] = bmn->chaves[bmn->mgrau];
            noh_novo->filhos[0] = bmn;
            noh_novo->filhos[1] = w;
        }
        else
        {
            noh_novo = bmn->pai;
            for (j = 1; j <= noh_novo->nchaves; j++)
            {
                if (noh_novo->chaves[j] == 0)
                {
                    noh_novo->chaves[j] = bmn->chaves[bmn->mgrau];
                    noh_novo->filhos[j] = bmn;
                    noh_novo->filhos[j + 1] = w;
                }
            }
        }
        noh_novo->nchaves++;

        w->pai = noh_novo;
        y->pai = w;
        z->pai = w;

        bm_noh_split_int(noh_novo, bmn, w);
    }
    else
    {
        return bmn;
    }
}

/**
 * faz a inseção de uma chave na página
 * @param bm_noh bmn página 
 * @param int chave chave a ser inserida
 *
 */

void bm_noh_insere(bm_noh *bmn, int chave)
{
    int i = bmn->nchaves - 1, j;

    if (bmn->eh_folha)
    {
        while (i >= 0 && bmn->chaves[i] > chave)
        {
            bmn->chaves[i + 1] = bmn->chaves[i];
            --i;
        }
        bmn->chaves[i + 1] = chave;
        bmn->nchaves++;
    }
    else
    {
        while (i >= 0 && bmn->chaves[i] > chave)
            --i;
        bm_noh_insere(bmn->filhos[i + 1], chave);
        if (bmn->filhos[i + 1]->nchaves == MAXCHAVES(bmn->mgrau) + 1)
        {
            bm_noh_split(bmn, bmn->filhos[i + 1], i + 1);
            i = bmn->nchaves - 1;
        }
    }
}

/**
 * faz a impressão de espaços para a função escrutina
 *
 */
void padding(char ch, int n)
{
    for (int i = 0; i < n; i++)
        putchar(ch);
}

/**
 * faz a impressão das chaves na página
 * @param bm_noh bmn página raiz 
 * @param int nivel nivel da arvore
 *
 */
void bm_noh_escrutina(bm_noh *bmn, int nivel)
{
    int i;
    if (bmn->eh_folha)
    {
        for (i = 0; i < bmn->nchaves; i++)
        {
            printf("\n");
            padding('\t', nivel + 1);
            printf("%d ", bmn->chaves[i]);
        }
    }
    else
    {
        bm_noh_escrutina(bmn->filhos[0], nivel + 1);
        for (i = 0; i < bmn->nchaves; i++)
        {
            printf("\n");
            padding('\t', nivel);
            printf("%d ", bmn->chaves[i]);
            //printf("%d[%d] ", bmn->chaves[i], nivel);
            bm_noh_escrutina(bmn->filhos[i + 1], nivel + 1);
        }
    }
}

/**
 * pesquisa uma chave na árvore
 * @param bm_noh bmn página raiz 
 * @param int chave chave a ser buscada
 *
 */
bm_noh *bm_noh_pesquisa_folha(bm_noh *bmn, int chave)
{
    int i = 0;
    while (i < bmn->nchaves && chave > bmn->chaves[i])
        i++;
    if (bmn->chaves[i] == chave && bmn->eh_folha)
        return bmn;
    else if (bmn->eh_folha)
        return NULL;

    return bm_noh_pesquisa(bmn->filhos[i], chave);
}

/**
 * pesquisa uma chave na árvore
 * @param bm_noh bmn página raiz 
 * @param int chave chave a ser buscada
 *
 */
bm_noh *bm_noh_pesquisa(bm_noh *bmn, int chave)
{
    int i = 0;
    while (i < bmn->nchaves && chave > bmn->chaves[i])
        i++;
    if (bmn->chaves[i] == chave)
        return bmn;
    if (bmn->eh_folha)
        return NULL;
    return bm_noh_pesquisa(bmn->filhos[i], chave);
}

int bm_noh_contem(bm_noh *bmn, int chave)
{
    if (bm_noh_pesquisa(bmn, chave))
        return 1;
    return 0;
}

/**
 * escreve conteúdo da página folha no disco
 * @param bm_noh bmn página folha 
 *
 */
void bm_noh_escrevedisc(bm_noh *bmn, s_artigo *art)
{
    FILE *parq;
    int j;
    int quantos_arts = 0;

    char *tmp = NULL;

    if (!bmn->eh_folha)
        erro(__func__, "arquivo: foi tentado escrever em disco pagina nao folha");

    tmp = (char *)malloc(sizeof(char) * (strlen(NOME_ARQ) + strlen(SUFIXO_BM) + 1));
    strcpy(tmp, NOME_ARQ""SUFIXO_BM);


    if (!(parq = fopen(tmp, "w+")))
    {
        free(tmp);
        erro(__func__, "arquivo: erro na criacao do arquivo .bm");
    }
    free(tmp);

    fseek(parq, 0, SEEK_END);
    if (ftell(parq) > sizeof(int))
    {
        rewind(parq);
        fread(&quantos_arts, sizeof(int), 1, parq);
    }
    fseek(parq, 0, SEEK_END);
    quantos_arts++;
    fwrite(&quantos_arts, sizeof(int), 1, parq);
    fseek(parq, 0, SEEK_END);

    for (j = 0; bmn->eh_folha && j < bmn->nchaves; j++)
    {
        if (bmn->chaves[j] == art->id)
        {
            bmn->dfilhos[j] = (long *)ftell(parq);
            fwrite(art, sizeof(s_artigo), 1, parq);
            break;
        }
    }
    fclose(parq);
}

/**
 * ler conteúdo do disco 
 * @param bm_noh bmn página 
 * @param int chave chave para a identificação no disco
 *
 */
s_artigo *bm_noh_ledisc(bm_noh *bmn, int chave)
{
    FILE *parq;
    int j;

    char *tmp;

    if (!bmn->eh_folha)
        erro(__func__, "arquivo: foi tentado ler em disco pagina nao folha");

    tmp =
        (char *)malloc(sizeof(char) * (strlen(NOME_ARQ) + strlen(SUFIXO_BM) + 1));
    strcpy(tmp, NOME_ARQ "" SUFIXO_BM);

    if (!(parq = fopen(tmp, "r")))
    {
        free(tmp);
        erro(__func__, "arquivo: erro na leitura do arquivo .bm");
    }
    free(tmp);

    for (j = 0; bmn->eh_folha && j < bmn->nchaves; j++)
    {
        s_artigo *a = (s_artigo *)malloc(sizeof(s_artigo));
        if (chave == bmn->chaves[j])
        {
            rewind(parq);
            fseek(parq, *bmn->dfilhos[j], SEEK_SET);
            fread(a, sizeof(s_artigo), 1, parq);
            fclose(parq);
            return a;
        }

        free(a);
    }
    fclose(parq);

    return NULL;
}


