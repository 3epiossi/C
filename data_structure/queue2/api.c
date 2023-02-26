#include <stdlib.h>
#include "define2.h"
void InitQueue(Queue* Q){
	(*Q)=NULL;
}	

int EnQueue(Queue* Q, content x){
	Queue new = (Queue)malloc(sizeof(Node));
	new->next = NULL;
	new->a = x;
	
	if((*Q)==NULL){
		(*Q) = (Queue)malloc(sizeof(Node));
		(*Q)->a = x;
		(*Q)->next = NULL;
		return 0;
	}
	if(((*Q)->next) == NULL){
		(*Q)->next = new;
		return 0;		
	}
	Queue son = (*Q)->next;
	Queue father = (*Q);

	while(son->next != NULL){
		father = father->next;
		son = son->next;
	}
	son->next = new;
	return 0;
}

void DeQueue(Queue *Q){
	Queue temp = (*Q);
	(*Q) = (*Q)->next;
	free(temp);
}

bool IsQueueEmpty(Queue Q){
	return Q == NULL ? false:true;
}
