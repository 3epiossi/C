/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int l = 0;
    int r = numsSize-1;
    int temp;
    while (l < r){
        if (nums[l]%2 != 0){
            while(r > l && nums[r]%2) --r;
            temp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = temp;
        }
        else{
            ++l;
            continue;
        }
    }
    return nums;
}