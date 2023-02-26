#ifndef _Queue_1
#define _Queue_1
#include<stdbool.h>
typedef char content;
typedef struct node{
	content a;
	struct node* next;
}Node;
typedef Node* ptrNode;
typedef ptrNode Queue;

void InitQueue(Queue*);
int EnQueue(Queue* , content);
void DeQueue(Queue*);
bool IsQueueEmpty(Queue);
#endif
