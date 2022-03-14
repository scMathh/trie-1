/**
 * inclusão baseado nas notas de aula da prof. Luciana
 */
int rb_insert(rb_n **t, rb_n *z)
{
    /**
     * y aponta para nó sentinela, rb_s (nó sentinela)
     * x é um ponteiro temporário para iteração feita 
     * no loop while mas tem como valor inicial a raiz
     * passada em t que é ponteiro duplo por que, poderá 
     * ser alterada nesta função e desejamos que estas alterações
     * persistam
     */
    rb_n *y = &rb_s; 
    rb_n *x = *t;

    /**
     * itera para chegar no nó folha da posicao a ser inserido o novo noh,
     * como está explícito, caso a chave seja menor que a do nó testado atualiza a refencia x 
     * com o nó a esquerda caso seja maior com o nó a diretia, em caso diferente destes
     * retorna a função com código de erro, seria o caso em que já existe chave igual
     * na árvore
     */
    while (x != &rb_s)
    {
        y = x;
        if (z->k < x->k)
            x = x->l;
        else if (z->k > x->k)
            x = x->r;
        else
            return -1;
    }

    /**
     * seta noh pai para o noh adicionado
     */
    z->p = y;

    /**
     * se esse noh adicionado eh unico y permance
     * nulo que neste caso apontaria para o pai que eh nulo
     * neste cenario torna o noh adicionado raiz
     * caso n adiciona na esquera ou diretia de acordo
     * com o valor da chave, noh recebe RED como padrao
     */
    if (y == &rb_s)
        *t = z;
    else if (z->k < y->k)
        y->l = z;
    else
        y->r = z;
    z->l = z->r = &rb_s;
    z->c = RED;

    /** ajuste */
    while (z->p->c == RED)
    {
        if (z->p == z->p->p->l)
        {
            y = z->p->p->r;
            if (y->c == RED)
            {
                z->p->c = BLACK;
                y->c = BLACK;
                z->p->p->c = RED;
                z = z->p->p;
            }
            else 
            {
                if (z == z->p->r)
                {
                    z = z->p;
                    rb_rot_esq(t, z);
                }
                z->p->c = BLACK;
                z->p->p->c = RED;
                rb_rot_dir(t, z->p->p);
            }
        }
        else
        {
            y = z->p->p->l;
            if (y->c == RED)
            {
                z->p->c = BLACK;
                y->c = BLACK;
                z->p->p->c = RED;
                z = z->p->p;
            }
            else 
            {
                if (z == z->p->l)
                {
                    z = z->p;
                    rb_rot_dir(t, z);
                }
                z->p->c = BLACK;
                z->p->p->c = RED;
                rb_rot_esq(t, z->p->p);
            }
        }
    }
    (*t)->c = BLACK;

    return 0;
}

