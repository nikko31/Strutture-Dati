/* 
 * File:   strutture.h
 * Author: nikko31
 *
 * Created on May 30, 2014, 11:23 PM
 */

#ifndef STRUTTURE_H
#define	STRUTTURE_H

#include <stdio.h>
#include <stdlib.h>

typedef int boolean;
typedef int Element;

typedef struct list_element 
{
    Element value;
    struct list_element *next;
} item;
typedef item* list;


/* ---- PRIMITIVE ---- */
extern list emptylist(void);
extern boolean empty(list);/* Restituisce TRUE se l e` la lista vuota, FALSE altrimenti. */
extern Element head(list);
extern list tail(list);
extern list cons(Element, list);
//--------------------->
extern Element copy(Element e);
extern boolean isEqual(Element e1,Element e2);
extern boolean isLess(Element e1, Element e2);
#endif	/* STRUTTURE_H */

