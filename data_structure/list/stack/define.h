#ifndef _guard
#define _guard
#include <stdbool.h>
typedef char element;
typedef struct node{
	element a;
	struct node* next;

}Node;
typedef Node* ptrNode;
typedef ptrNode stack;


void InitStack(stack *s);
int push(element x, stack *s);
void pop(stack *s);

#endif 



