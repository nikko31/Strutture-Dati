/* 
 * File:   strutture.c
 * Author: nikko31
 *
 * Created on May 30, 2014, 11:35 PM
 */

#include "strutture.h"
//-------->PRIMITIVE------------------>

list emptylist() 
{
    return NULL;
}

boolean empty(list l) 
{
    return (l==NULL);
}

Element head(list l) 
{
    if (empty(l)) 
        abort();
    return l->value;
}

list tail(list l) 
{
    if (empty(l)) abort();
    else
    return l->next;
}

list cons(Element e, list l) 
{
    list t;
    t = (list) malloc(sizeof(item));
    t->value=copy(e);
    t->next=l;
    return t;
}
//--------------------------->
Element copy(Element e)
{
    Element el;
    el=e;
    return el;  
}

boolean isEqual(Element e1,Element e2) 
{
    return (e1 == e2);
}

boolean isLess(Element e1, Element e2)
{
return (e1 < e2);
}

void printElement(Element el)
{
    printf("%d", el);
}

void showlist(list l)    
{
    printf("[");
    while (!empty(l)) {
    printElement(head(l));
    l = tail(l);
    if (!empty(l)) printf(", ");
    }
    printf("]\n");
}