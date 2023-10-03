int numIdenticalPairs(int* nums, int numsSize){
    int hashset[101] = {};
    int res = 0;
    for(int i = 0; i < numsSize; ++i){
        res += hashset[nums[i]];
        ++hashset[nums[i]];
    }
    return res;
}