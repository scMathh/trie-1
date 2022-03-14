/*
 * aluno: joilnen leite, daniel morais, matheus silva
 */
#include <stdio.h>
#include <string.h>

#include "jcurses.h"
#include "checklist.h"

/** mostra itens da avaliacao 
 * @param i especifica que itens estao selecionados 
 */
void tela_checklist(int i)
{
    int l = 8, c = 16, bo = 1UL;
    static unsigned int cklst_estado = 0;
    cklst_estado |= i ; 

    CKLSITEM(l++, c + 18, 0, S_UNDERL"avaliacao"S_NORM);
    CKLSITEM(l++, c, 0, " ");
    CKLSITEM(l++, c, cklst_estado & bo, ITEM_1); bo <<= 1;
    CKLSITEM(l++, c, cklst_estado & bo, ITEM_2); bo <<= 1;
    CKLSITEM(l++, c, cklst_estado & bo, ITEM_3); bo <<= 1;
    CKLSITEM(l++, c, cklst_estado & bo, ITEM_4); bo <<= 1;
    CKLSITEM(l++, c, cklst_estado & bo, ITEM_5); bo <<= 1;
    CKLSITEM(l++, c, cklst_estado & bo, ITEM_6); bo <<= 1;

    CMR1;
}


