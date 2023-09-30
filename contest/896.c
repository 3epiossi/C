#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isMonotonic(int* nums, int numsSize){
    int flag;
    int i = 0;
    while(i < numsSize-1 && nums[i] == nums[i+1]) ++i ;
    if (numsSize-i > 1){
        flag = (nums[i] > nums[i+1] ? 1:(nums[i] < nums[i+1] ? -1:0));
    }
    for(i = 1; i < numsSize-1; ++i){
        if (abs(flag-(nums[i] > nums[i+1] ? 1:(nums[i] < nums[i+1] ? -1:0))) == 2) return false;
    }
    return true;
}
int main(){
    int array[3] = {1, 3, 2};
    printf("%d", isMonotonic(array, 3));
    return 0;
}