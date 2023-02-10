#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
void init(List* pfirst){
    *pfirst = NULL;
}
bool full(const List* pfirst){
    List test=NULL;
    test=(Node*)malloc(sizeof(Node));
    if(test==NULL){
        free(test);
        return true;
    }
    else{
        free(test);
        return false;
    }
}
bool empty(const List* pfirst){
    if(*pfirst==NULL){
        return true;
    }
    else{
        return false;
    }
}
void add(char name[],int rating, List* pfirst){
    List now;
    List scan=*pfirst;
    now=(Node*)malloc(sizeof(Node));
    now->next=NULL;
    if(now==NULL){
        puts("memory allocated failure");
    }
    now->content.rating=rating;
    strcpy(now->content.title,name);
    if(*pfirst==NULL){
        *pfirst=now;
    }
    else{
        while(scan->next!=NULL){
            scan=scan->next;
        }
        scan->next=now;
    }
}
void print(const List* pfirst){
    List _list= *pfirst;
    List _free=*pfirst;
    puts("the following is your input");
    while(_list!=NULL){
        printf("the title:%s. the rating:%d\n"
        ,_list->content.title,_list->content.rating);
        _list=_list->next;
    }
     _list= *pfirst;
    while(_list!=NULL){
        _free=_list;
        _list=_free->next;
        free(_free);

    }
}