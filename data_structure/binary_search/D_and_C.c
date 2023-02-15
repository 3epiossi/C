#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int max_sum(const int arr[], int left, int right);
int compare(int a, int b, int c);
int main (void){
    char input[50][5]={};
    char chara;
    int arr[50] = {};
    int i = 0;
    int n = 0;
    int max = 0; 
    printf("please input the array's element\n(enter # to stop)\n");
    while(scanf("%s",input[n]) && input[n][0] != '#'){
        n++;
    }
    
    for(i = 0; i < n; i++){
        arr[i]= atoi(input[i]);
    }
    

    max= max_sum(arr, 0, i-1);
    printf("the max subsequence sum is %d",max);
    return 0;
}

int max_sum(const int arr[], int left, int right){
    int in_right_max, in_left_max;
    int cross_center_right, cross_center_left;
    int max_plus_right, max_plus_left;
    int center;
    int count;
    center = (right+ left)/2;

    if(right== left){
        return arr[right];
    }

    in_right_max = max_sum(arr, center+ 1, right);
    in_left_max = max_sum(arr, left, center);

    max_plus_right = -(INT32_MAX -1); cross_center_right = 0;
    for(count= center+1; count<= right; count++){
        cross_center_right += arr[count];
        
        if(max_plus_right< cross_center_right){
            max_plus_right = cross_center_right;
        }
    }

    max_plus_left= -(INT32_MAX -1); cross_center_left= 0;
    for(count= center; count>= left; count--){
        cross_center_left += arr[count];
        
        if(max_plus_left< cross_center_left){
            max_plus_left = cross_center_left;
        }
    }

    return compare(in_right_max, in_left_max, max_plus_right+ max_plus_left);
    
}

int compare(int a, int b, int c){
    int max= -(INT32_MAX- 1);
    int arr[3]= {a, b, c};
    int count;
    for(count= 0; count< 3; count++){
        if(max < arr[count]){
            max = arr[count];
        }
    }
    return max;
}