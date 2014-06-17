/* 
 * File:   main.c
 * Author: Nikko31
 *
 * Created on May 30, 2014, 11:22 PM
 */

#include "strutture.h"
/*
 *  
 */
int main(int argc, char** argv) {
    list l1 = emptylist();
    int el;
    do {
        printf("\n Introdurre valore:\t");
        el=getElement();
        l1 = insord2(el, l1);
    } while (el!=0); /* condiz. arbitraria */
    showlist(l1);
    getchar();
    return 0;
}

