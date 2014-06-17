/* 
 * File:   struttureAST.h
 * Author: nikko31
 *
 * Created on June 17, 2014, 4:25 PM
 */

#ifndef STRUTTUREAST_H
#define	STRUTTUREAST_H

#include <stdio.h>
#include <stdlib.h>


typedef  int  element;

typedef struct	treeElement {
	element	value;
	struct treeElement  *left, *right;
} node;

typedef  node *tree;

typedef  enum {false, true} boolean;

extern void showEl(char a);
extern boolean empty(tree t);
extern tree emptyTree(void);
extern element root(tree t);
extern tree left(tree t);
extern tree right(tree t);
extern tree consTree(element e, tree l, tree r);
extern void preOrder(tree t);
extern void inOrder(tree t);
extern void postOrder(tree t);
extern tree succ(tree t);
extern tree copy(tree t);
extern tree delete(tree t, element e);
extern tree insertBinOrd(element e, tree t);


#endif	/* STRUTTUREAST_H */

