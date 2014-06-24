
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{true,false} boolean;
typedef struct Elem {
    long val;
    char str[50];
    struct Elem *next;
} Elem;
typedef Elem *List;

List empty_list(){
    return NULL;
}

List cons(Elem e, List l)
{
    List t;
    t = (List)malloc(sizeof(Elem));
    t->val = e.val;
    strcpy(t->str, e.str);
    t->next = l;
    return t;
}

void printelement(Elem el)
{
    printf("%d , %s", el.val,el.str);
}

boolean isempty(List l){
    return l == NULL;
}

Elem head(List l){
    return *l;
}

List tail(List l){
    if (isempty(l)) abort();
    else
        return l->next;
}

void show_list(List l){

    printf("[");
    while (!isempty(l)) {
        printelement(head(l));
        l = tail(l);
        if (!isempty(l))
            printf(" | ");
    }
    printf("]\n");
}

List inserisci(FILE *f,List l)
{
    Elem e;
    while (fscanf(f, "%d , \" %s ", &(e.val), (e.str)) != EOF)
    {
        e.str[strlen(e.str) - 1] = 0;
        l = cons(e, l);
    }
    return l;
}
List inserisci_incoda(Elem e, List l)
{
    List tmp = l;
    while (!isempty(l))
    {
        l = tail(l);
       
    }
    l = cons(e, l);
    return tmp;
}

List join(List l1, List l2)
{
    boolean b=true ;
    List  tmp =empty_list();
    List tmp2 = l2;
    while (!isempty(l1))
    {
        l2 = tmp2;
        while (!isempty(l2))
        {
            if (l1->val == l2->val)
            {
                strcat(l1->str, l2->str);
                b = false;
            }
            l2 = tail(l2);
        }
        if (b == false)
            tmp = cons(*l1, tmp);
        b = true;
        l1 = tail(l1);
    }
    return tmp;
}

int main(int argc, char** argv) {
   
    FILE* f1;
    FILE* f2;
    List l1 = empty_list();
    List l2 = empty_list();
    /*lettura dai file*/
    if ((f1 = fopen("file1.txt", "rt")) == NULL) {
        fprintf(stderr, "Errore di apertura del file 1\n");
        exit(1);
    }
    if ((f2 = fopen("file2.txt", "rt")) == NULL) {
        fprintf(stderr, "Errore di apertura del file 2\n");
        exit(2);
    }
    /*inserimento nelle liste*/
    l1=inserisci(f1,NULL);
    l2 = inserisci(f2, NULL);
    /*join*/
    l1 = join(l1, l2);
    show_list(l1);
    getchar();
    return 0;
}
