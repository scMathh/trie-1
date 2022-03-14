/*
 * aluno: joilnen leite, daniel morais, matheus silva
 */
#ifndef CHECKLIST_H_
#define CHECKLIST_H_

/*
 * aluno: joilnen leite
 */

/** mostra itens da avaliacao 
 * @param i especifica que itens estao selecionados 
 */
void tela_checklist(int i);

/** itens da avalicao mostrados na tela */
#define ITEM_1 "1 impressao dos artigos"
#define ITEM_2 "2 busca por id"
#define ITEM_3 "3 insersao de novo artigo"
#define ITEM_4 "4 remocao de um artigo"
#define ITEM_5 "5 listagem de todos os art. em ordem (de um id)"
#define ITEM_6 "6 testes"

/** usado na operacao de bits na mostra de itens da avalicao */
enum {I_NONE, I_1, I_2, I_3, I_4, I_5, I_6, I_MAX};

#endif


