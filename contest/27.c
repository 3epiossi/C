#include <stdio.h>
#include <stdlib.h>
int removeElement(int* nums, int numsSize, int val){
    if (numsSize == 0 || (numsSize == 1 && nums[0] == val)){
        return 0;
    }
    else if (numsSize == 1 && nums[0] != val){
        return 1;
    }
    int pr = 0;
    int go = 0;
    while (go < numsSize && nums[go] == val) go += 1;
    while( go < numsSize ){
        nums[pr] = nums[go];
        go += 1;
        pr += 1;
        while (go < numsSize && nums[go] == val) go += 1;
    }
    return pr;
}