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

typedef  enum {false, true} boolean;

typedef int element;

typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item* list;

/* ---- PRIMITIVE ---- */
extern list emptylist(void);
extern boolean empty(list);/* Restituisce TRUE se l e` la lista vuota, FALSE altrimenti. */
extern element head(list);
extern list tail(list);
extern list cons(element, list);
//-------------------->
extern element copy(element e);
extern boolean isEqual(element e1,element e2);
extern boolean isLess(element e1, element e2);
extern void printelement(element el);
extern void showlist(list l);  
extern element getElement();
extern list insord2(element e, list l);
extern list insord(element e, list l);
#endif	/* STRUTTURE_H */

