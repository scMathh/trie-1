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
#define ITEM_1 "1 adicionar: adiciona uma nova"
#define ITEM_2 "2 excluir: exclui uma string"
#define ITEM_3 "3 contem string: verifica string está contida"
#define ITEM_4 "4 vazio: verifica se um conjunto informado esta vazio"
#define ITEM_5 "5 tamanho: informa o número de elementos do conjunto"
#define ITEM_6 "6 Imprimir: imprime as strings contidas no conjuntoe"
#define ITEM_7 "7 contem prefixo:  strinc s e conjunto pr.strings"

/** usado na operacao de bits na mostra de itens da avalicao */
enum {I_NONE, I_1, I_2, I_3, I_4, I_5, I_6, I_7, I_MAX};

#endif

