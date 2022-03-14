/**
 * funcao que faz trocas auxiliares na delecao
 * @param u noh que eh trocado por outro em seu lugar
 * @param v noh que eh colocado no lugar do noh anterior
 */
static int rb_transplant(rb_n **t, rb_n *u, rb_n *v)
{
    if (u->p == &rb_s)
        *t = v;
    else if (u == u->p->l)
        u->p->l = v;
    else
        u->p->r = v;
    if(v)
        v->p = u->p;
    return 0;
}

/**
 * @param x noh raiz
 * retorma o noh mais a esquerda na arvore 
 * ou subarvore
 */
static rb_n *tree_minimum(rb_n *x)
{
    rb_n *a = x;
    while (a->l != &rb_s)
        a = a->l;
    return a;
}

/**
 * sucessor baseado nas notas e no livro do cormen, reescrito
 * e consegui diminuir em duas linhas do algoritmo original
 */
static rb_n* sucessor(rb_n *x)
{
    rb_n *y = NULL;
    if (x->r != &rb_s)
        return tree_minimum(x->r);
    while ((y = x->p) && x == y->r)
        x = y;
    return y;
}


int rb_rot_esq(rb_n **t, rb_n *x)
{
    rb_n *y = x->r;
    x->r = y->l;
    if (y->l != &rb_s)
        y->l->p = x;
    y->p = x->p;
    if (x->p == &rb_s)
        *t = y;
    else if (x == x->p->l)
        x->p->l = y;
    else
        x->p->r = y;
    y->l = x;
    x->p = y;

    return 0;
}

int rb_rot_dir(rb_n **t, rb_n *x)
{
    rb_n *y = x->l;
    x->l = y->r;
    if (y->r != &rb_s)
        y->r->p = x;
    y->p = x->p;
    if (x->p == &rb_s)
        *t = y;
    else if (x == x->p->r)
        x->p->r = y;
    else
        x->p->l = y;
    y->r = x;
    x->p = y;

    return 0;
}

