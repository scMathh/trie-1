/**
 * deleta noh da arvore red black
 * @param t ponteiro duplo para raiz, assim pq ele pode ser alterado dentro da funcao
 * e manter a alteracao depois do retorno da fucao
 * @param z ponteiro para o noh a ser deletado, para deletar por chave o TAD deve
 * passar a saida da funcao pesquisar, num arranjo funcional na chamada
 */
int rb_delete(rb_n **t, rb_n *z)
{
    rb_n *x = &rb_s;
    rb_n *y = z;
    unsigned char yoc = z->c;

    if (z->l == &rb_s)
    {
        x = z->r;
        rb_transplant(t, z, z->r);
    }
    else if (z->r == &rb_s)
    {
        x = z->l;
        rb_transplant(t, z, z->l);
    }
    else
    {
        // y = tree_minimum(z->r);
        y = sucessor(z);
        yoc = y->c;
        x = y->r;
        if (y->p == z)
            x->p = y;
        else
        {
            rb_transplant(t, y, y->r);
            y->r = z->r;
            y->r->p = y;
        }
        rb_transplant(t, z, y);
        y->l = z->l;
        y->l->p = y;
        y->c = z->c;
    }

    if (yoc == BLACK)
    {
        rb_n *w = &rb_s;
        while (x != *t && x->c == BLACK)
        {
            if (x == x->p->l)
            {
                w = x->p->r;
                if (w->c == RED)
                {
                    w->c = BLACK;
                    x->p->c = RED;
                    rb_rot_esq(t, x->p);
                    w = x->p->r;
                }

                if (w->l->c == BLACK && w->r->c == BLACK) 
                {
                    w->c = RED;
                    x = x->p;
                }
                else
                {
                    if (w->r->c == BLACK)
                    {
                        w->l->c = BLACK;
                        w->c = RED;
                        rb_rot_dir(t, w);
                        w = x->p->r;
                    }

                    w->c = x->p->c;
                    x->p->c = BLACK;
                    w->r->c = BLACK;
                    rb_rot_esq(t, x->p);
                    x = *t;
                }
            }
            else 
            {
                w = x->p->l;
                if (w->c == RED)
                {
                    w->c = BLACK;
                    x->p->c = RED;
                    rb_rot_dir(t, x->p);
                    w = x->p->l;
                }

                if (w->l->c == BLACK && w->r->c == BLACK)
                {
                    w->c = RED;
                    x = x->p;
                }
                else
                {
                    if (w->l->c == BLACK)
                    {
                        w->r->c = BLACK;
                        w->c = RED;
                        rb_rot_esq(t, w);
                        w = x->p->l;
                    }

                    w->c = x->p->c;
                    x->p->c = BLACK;
                    w->l->c = BLACK;
                    rb_rot_dir(t, x->p);
                    x = *t;
                }
            }
        }
        x->c = BLACK;
    } /* if (yoc == BLACK) */

    return 0;
}

