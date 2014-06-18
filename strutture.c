/* 
 * File:   strutture.c
 * Author: nikko31
 *
 * Created on May 30, 2014, 11:35 PM
 */

#include "strutture.h"
/*--------PRIMITIVE------------------*/

list emptylist() 
{
return NULL;
}

boolean empty(list l) 
{
    return (l==NULL);
}

element head(list l) 
{
    if (empty(l)) abort();
    else
    return l->value;
}

list tail(list l)
{
    if (empty(l)) abort();
    else
    return l->next;
}

list cons(element e, list l) 
{
    list t;
    t = (list) malloc(sizeof(item));
    t->value=copy(e);
    t->next=l;
    return t;
}

//---------------------------
element copy(element e)
{
    element el;
    el=e;
    return el;  
}

boolean isEqual(element e1,element e2) 
{
    return (e1 == e2);
}

boolean isLess(element e1, element e2)
{
return (e1 < e2);
}

void printelement(element el)
{
    printf("%d", el);
}

void showlist(list l)    
{
    printf("[");
    while (!empty(l)) {
        printelement(head(l));
        l = tail(l);
        if (!empty(l)) 
            printf(", ");
    }
    printf("]\n");
}

list insord(element e, list l)
{
    list t;
    if(empty(l) || !isLess(head(l), e)){
        t = cons(e, l); //se vuoto o se head<e
        //t->next = l;
        return t;
    }
    return cons(head(l), insord(e, tail(l)));//ricostruisco con head + insord(tail)
}

list insord2(element e, list l)
{
    list l1 = NULL, root = l;
    list t;
    if(empty(l) || !isLess(head(l), e)) //se vuoto o head>e inserisci in testa con cons
    {
        t = cons(e, l);
        return t;
    }
    t = cons(e, NULL);
    while(!empty(l) && isLess(head(l), e))//finchè è pieno e finchè head>e faccio il ciclo
    {
        l1=l;   //l1 diventa l     l____l1======|
        l = tail(l);//tolgo la testa 
    }
    l1->next = t; //quando esco avro che l è finita  oppure ho trovato head>
    t->next = l;
    return root;
}

element getElement()
{
    element el;
    scanf("%d", &el);
    return el;
}