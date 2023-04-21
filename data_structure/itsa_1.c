#include <stdio.h>
#include <stdlib.h>
#define ROW 50
#define COL 50
void left(char*);
void right(char*);
void go(int,char,int*,int*,int,int(*ar)[COL]);
void print(int(*ar)[COL],int,int);
void pen_up(int);
int main (void){
    int ar[ROW][COL]={0};
    char dir='r';
    int dist=0;
    int command=0;
    int posR=0,posC=0;
    int maxPosR=0,maxPosC=0;
    int pen=1;
    while(command!=9){
        scanf("%d",&command);
        switch(command){
            case 3:
                right(&dir);
                break;
            case 4:
                left(&dir);
                break;
            case 5:
                scanf(",%d",&dist);
                go(dist,dir,&posR,&posC,pen,ar);
                if(maxPosR<=posR){
                    maxPosR=posR;
                }
                if(maxPosC<=posC){
                    maxPosC=posC;
                }
                break;
            case 6:
                print(ar,maxPosR,maxPosC);
                break;
            case 1:
                pen=1;
                break;
            case 2:
                pen=2;
                break;
            default:
                break;
        }
        
    }
}
void right(char*dir){
    switch(*dir){
        case 'r':
            *dir='d';
            break;
        case 'd':
            *dir='l';
            break;
        case 'l':
            *dir='u';
            break;
        case 'u':
            *dir='r';
            break;
        default:
            break;
    }
}
void left(char*dir){
    switch(*dir){
        case 'r':
            *dir='u';
            break;
        case 'u':
            *dir='l';
            break;
        case 'l':
            *dir='d';
            break;
        case 'd':
            *dir='r';
            break;
        default:
            break;
    }
}
void go(int dist,char dir,int*posR,int*posC,int pen,int ar[][COL]){
    int count=0;
    if(pen==1){
        switch(dir){
        case 'r':
            if(*posC+dist<=ROW-1){
                for(count=0;count<dist;count++){
                    *posC+=1;
                }
            }
            else{
                *posC=ROW-1;
            }
            break;
        case 'l':
            if(*posC-dist>=0){
                for(count=0;count<dist;count++){
                    *posC-=1;
                }
            }
            else{
                *posC=0;
            }
            break;
        case 'u':
            if(*posR-dist>=0){
                for(count=0;count<dist;count++){
                    *posR-=1;
                }
            }
            else{
                    *posR=0;
            }      
            break;
        case 'd':
            if(*posR+dist<=COL-1){
                for(count=0;count<dist;count++){
                    *posR+=1;
                }
            }
            else{
                *posR=COL-1;
            }
    }
    }
    if(pen==2){
        switch(dir){
        case 'r':
            for(count=0;count<dist;count++){
                *posC+=1;
                ar[*posR][*posC]=1;
                if(*posC==COL-1){
                    break;
                }
            }
            break;
        case 'l':
            for(count=0;count<dist;count++){
                *posC-=1;
                ar[*posR][*posC]=1;
                if(*posC==0){
                    break;
                }
            }
            break;
        case 'u':
            for(count=0;count<dist;count++){
                *posR-=1;
                ar[*posR][*posC]=1;
                if(*posR==0){
                    break;
                }
            }
            break;
        case 'd':
            for(count=0;count<dist;count++){
                *posR+=1;
                ar[*posR][*posC]=1;
                if(*posR==ROW-1){
                    break;
                }
            }
            break;
    }
    }
    
}
void print(int ar[][COL],int maxPosR,int maxPosC){
    int count=0;
    int num=0;
    for(count=0;count<=maxPosR;count++){
        for(num=0;num<=maxPosC;num++){
            if(ar[count][num]==0){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}