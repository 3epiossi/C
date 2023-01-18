#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
char* s_get(char[],int);
int main (void){
    List first;
    char name[LEN]={[0]='a'};
    int evalue=0;
    bool flag=true;
    init(&first);
    if(full(&first))
        puts("sorry,the memory is full");
        puts("please input the movie's title(enter nothing to quit)");
    while(s_get(name,LEN)!=NULL&&name[0]!='\0'){
        puts("please input the rating");
        fflush(stdin);
        do{
            flag=scanf("%d",&evalue);
            if(evalue>=0&&evalue<=10)
                break;
            else{
                puts("your input is out of range,please input again");
                flag=false;
            }
        }while(!flag);
        add(name,evalue,&first);
        puts("please input anothe movies title(input nothing to quit)");
        fflush(stdin);
    }
    if(first==NULL)
        puts("your didn't input any data");
    else
        print(&first);
    return 0;
}
char* s_get(char name[],int lim){
    char* ret_val;
    char* find;
    ret_val=fgets(name,lim-1,stdin);
    find=strchr(name,'\n');
    if(find){
        *find='\0';
    }
    return ret_val;
}