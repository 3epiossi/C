#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char findTheDifference(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    char c = 0;
    for (int i = 0; i < slen; ++i){
        c ^= *(s+i);
    }
    for (int i = 0; i < tlen; ++i){
        c ^= t[i];
    }
    return c;
}
int main(){
    char* s = "abcde";
    char* t = "abcd";
    printf("%c", findTheDifference(s, t)); 
    return 0;
}