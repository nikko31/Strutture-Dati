/* 
 * File:   strutture.c
 * Author: nikko31
 *
 * Created on May 30, 2014, 11:35 PM
 */

#include "strutture.h"
/*--------PRIMITIVE------------------*/

list emptylist() {
return NULL;
}
boolean empty(list l) {
    return (l==NULL);
}
element head(list l) {
    if (empty(l)) abort();
    else
    return l->value;
}
list tail(list l) {
    if (empty(l)) abort();
    else
    return l->next;
}
list cons(element e, list l) {
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
    if (!empty(l)) printf(", ");
    }
    printf("]\n");
}