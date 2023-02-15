//用二分查找法尋找有無主要元素（該數占數組超過n/2)
#include <stdio.h>
#include <stdlib.h>
int right_search(int left, int right,int pivot, int a[]);
int left_search(int left, int right, int pivot,int a[]);
int main(void){
    int arr[50]={};
    char ch_int[50][5]={};
    int set[50]={};set[0]=-1;
    int count = 0;
    char ch;
    int i,j,k=0;
    int sum = 0;
    while((ch = getchar()) != '#'){
        
        if(ch == ' '){
            count++;
            k=0;
            continue;
        }

        if(ch != ' '){
            ch_int[count][k]=ch;
            k++;
        }
    }//count代表的是數組底標，不是數組個數，因為是數空白格的數量

    k=0;

    while(ch_int[k][0] != '\0'){
        arr[k] = atoi(ch_int[k]);
        arr[k+1] = -1;
        k++;
    }

    for(i=0;i<=count;i++){//數組轉set，相當重要
        for(j=0;j<=sum;j++){
            if(set[j]==-1){
                set[j]=arr[i];
                set[j+1]=-1;
                sum=j+1;
                break;
            }
            if(set[j]==arr[i]){
                break;
            }
        }
    }
    
    for(i=0; set[i]!=-1; ){
        if( (right_search((count)/2+1, count, set[i], arr) + 
        left_search(0, (count)/2, set[i], arr))  < (count+1)/2+1){
            i++;
            continue;
        }
        printf("%d ", set[i]);
        i++;
    }

    return 0;
}

int right_search(int left,int right, int pivot, int a[]){
    if(right-left == 1){
        if(pivot==a[left] && pivot==a[right]){
            return 2;
        }
        else if(pivot == a[left] || pivot == a[right]){
            return 1;
        }
        else{
           return 0;
        }
    }
    if(right-left == 0){
        if(pivot == a[left]){
            return 1;
        }
        else{
            return 0;
        }
    }
    int center = (right+left)/2;
    return (right_search((center+1), right, pivot, a)+ left_search(left, center, pivot, a));
}
int left_search(int left,int right, int pivot, int a[]){
    if(right-left == 1){
        if(pivot==a[left] && pivot==a[right]){
            return 2;
        }
        else if(pivot == a[left] || pivot == a[right]){
            return 1;
        }
        else{
           return 0;
        }
        if(right-left == 0){
        if(pivot == a[left]){
            return 1;
        }
        else{
            return 0;
        }
    }
    }
    int center = (right+left)/2;
    return (right_search((center+1), right, pivot, a)+ left_search(left, center, pivot, a));
}