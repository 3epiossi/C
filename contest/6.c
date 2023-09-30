#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * convert(char * s, int numRows){
    if(numRows == 1) return s;
    char** array = (char**) calloc(numRows, sizeof(char*));
    for(int i = 0; i < numRows; ++i){
        array[i] = (char*) calloc(1000,sizeof(char));
    } 
    int length = strlen(s);
    int count = 0;
    int row = 0;
    int direction = 1;
    int col = 0;
    while(count < length){
        if(direction == 1){
            if(row < numRows){
                strncat(array[row], (char[]){s[count], '\0'}, 1000);
                ++row;
                ++count;
            }
            else{
                row = numRows-2;
                ++col;
                direction = -1;
            }
        }
        else{
            if(row >= 0){
                strncat(array[row], (char[]){s[count], '\0'}, 1000);
                --row;
                ++count;
            }
            else{
                row = 1;
                ++col;
                direction = 1;
            }
        }
    }
    char* res = (char*) calloc(1000, sizeof(char));

    for(int i = 0; i < numRows; ++i)
        strncat(res, array[i], 1000);
    
    for(int i = numRows-1; i >= 0; --i ){
        free(array[i]);
    }
    free(array);
    return res;
    
}
int main(){
	printf("%s", convert("abcdef", 3));
    return 0;
}