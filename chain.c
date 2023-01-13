#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TFILE 45
#define FMAX  5
struct film{
    char title[TFILE];
    int rating;
    struct film* next;
};
char *s_get(char str[],int lim);
int main (void){
    struct film* prev;
    struct film* header=NULL;
    struct film* current;
    char temp[TFILE];
    int i=0;
    int j;
    puts("enter the first movie title");
    while(s_get(temp,FMAX)!=NULL&& temp[0]!='\0'){
        current=(struct film*)malloc(sizeof(struct film));
        if(header==NULL){
            header=current;
        }
        else{
            prev->next=current;
        }
        current->next=NULL;
        strcpy(current->title,temp);
        puts("input the rating [0,10]");
        scanf("%d",&current->rating);
        puts("input the next movie's title");
        fflush(stdin);
        prev=current;
    }
    if(header==NULL){
        puts("data are empty");
    }
    else{
        puts("here are movie list");
        while(header!=NULL){
            current=header;
            printf("the movie:%s the rating:%d\n",current->title,current->rating);
            header=current->next;
            free(current);
        }
    }
    puts("bye");
    exit(EXIT_SUCCESS);
    
    
}
char* s_get(char *st,int n){
    char* ret_val;
    char* find;
    ret_val=fgets(st,n,stdin);
    if(ret_val){
        find=strchr(st,'\n');
        if(find){
            *find='\0';
        }
        else{
            fflush(stdin);
        }
    }
    return ret_val;
}