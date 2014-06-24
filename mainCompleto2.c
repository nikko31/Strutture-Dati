
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{true,false} boolean;
typedef char stringa[20];
typedef struct Elem {
    stringa val;
    struct Elem *sx;
    struct Elem *dx;
} Elem;

typedef Elem *Tree;

boolean isempty(Tree t)
{
    return t == NULL;
}
Tree emptytree()
{
    return NULL;
}
Tree cons(Elem e, Tree sx, Tree dx)
{
    Tree t = (Elem*)malloc(sizeof(Elem));
    strcpy(t->val, e.val);
    t->dx = dx;    t->sx = sx;
    return t;
}
Elem root(Tree t)
{
    return *t;
}
Tree left(Tree t)
{
    return t->sx;
}
Tree right(Tree t)
{
    return t->dx;
}

Tree insord(Elem e, Tree t)
{
    Tree tmp = t;
    char cmp;
    if (isempty(t))
        return cons(e, emptytree(), emptytree());

    while (!isempty(t)) {
        cmp = strcmp(e.val, root(t).val);

        if (cmp<=0){
            if (isempty(left(t))){
                t->sx = cons(e, emptytree(), emptytree());
                t = left(t);
            }
            t = left(t);
        }
        else {
            if (isempty(t->dx)){
                t->dx = cons(e, emptytree(), emptytree());
                t = right(t);
            }
            t = right(t);
        }
    }

    return tmp;
}

void showEl(Elem e)
{
    printf("%s", e.val);
}
Elem ma;
void piuLunga(Tree t) {
    if (!isempty(t)) {
        if (strlen(t->val) > strlen(ma.val))
            ma = *t;
       
        piuLunga(left(t)); piuLunga(right(t));
    }
}

void inOrder(Tree t) {
    if (!isempty(t)) {
        inOrder(left(t));
        printf("\t"); showEl(root(t));
        inOrder(right(t));
    }
}

void inOrderD(Tree t) {
    if (!isempty(t)) {
        inOrderD(right(t));
        printf("\t"); showEl(root(t));
        inOrderD(left(t));
    }
}

void postOrder(Tree t) {
    if (!isempty(t)) {
        postOrder(left(t)); postOrder(right(t));
        printf("\t"); showEl(root(t));
    }
}

Elem massimo(Tree t)
{
    if (isempty(t))
        abort();
    while (!isempty(t->dx))
        t = t->dx;
    return *t;
}

void main()
{
    FILE *f;
    Elem e;
    Tree t = emptytree();
    if ((f = fopen("file3.txt", "rt")) == NULL)
    {
        fprintf(stderr, "Errore di apertura del file 1\n");
        exit(1);
    }
    while (fscanf(f,"%s", &(e.val)) != EOF)
    {
        t = insord(e,t);
    }
    piuLunga(t);
    printf("%s", ma.val);
    getchar();
    fclose(f);
}
