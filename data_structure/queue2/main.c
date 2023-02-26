#include <stdio.h>
#include <stdlib.h>
#include "define2.h"

int main(void){
	Queue Q;
	Queue count;
	InitQueue(&Q);
	EnQueue(&Q,'C');
	EnQueue(&Q,'h');	
	EnQueue(&Q,'a');
	EnQueue(&Q,'n');
	EnQueue(&Q,'g');
	DeQueue(&Q);
	DeQueue(&Q);
	DeQueue(&Q);
	DeQueue(&Q);
	DeQueue(&Q);
	EnQueue(&Q,'n');

	count = Q;
	while(IsQueueEmpty(count)){
		printf("%c",count->a);
		count = count->next;
	}
	return 0;

}
