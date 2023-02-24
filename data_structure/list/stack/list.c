#include <stdio.h>
#include <stdlib.h>
#include "define.h"
int main (void){
	char c;
	stack s,temp;
	s = malloc(sizeof(Node));
	if(s ==NULL)
		printf("errer 2");

	InitStack(&s);//記得要修改地址，要用指針的指針來傳遞值
	push('h',&s);
	push('k',&s);
	pop(&s);
	push('g',&s);
	push('n',&s);
	push('a',&s);
	push('h',&s);
	push('C',&s);
	while(s != NULL){
		temp = s;
		printf("%c",s->a);
		s = s->next;
		free(temp);
	}
	return 0;

}
