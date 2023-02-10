#ifndef CHECK
#define CHECK
#define LEN 50
#include <stdbool.h>
typedef struct item{
    char title[50];
    int rating;
}Item;
typedef struct node{
    Item content;
    struct node* next;
}Node;
typedef Node* List;
void init(List* );
bool full(const List*);
bool empty(const List*);
void add(char[],int, List*);
void print(const List*);
#endif