#include <stdio.h>
#include <stdlib.h>
#include "define.h"
void InitStack(stack *s){
	(*s)->a = '\0';
	(*s)->next = NULL;
}

void pop(stack *s){
	stack temp;
	temp = (*s);
	*s = (*s)->next;
	free(temp);
}
int push(element x, stack *s){
	stack new;
	new = malloc(sizeof(Node));
	if (new == NULL){
		printf("errer 1");
		exit(EXIT_FAILURE);
	}
	new->a = x;
	new->next = (*s);
	*s = new;
	return 0;
}
