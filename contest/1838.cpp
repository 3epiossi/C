class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int l = 0, r = 1;
        int s = 0, diff = 0, maxWid = 0;
        while( r < nums.size()){
            r = max(r, l+1);
            while(r < nums.size() and s+diff+(nums[r-1]-nums[r]) <= k){
                s += (diff+nums[r-1]-nums[r]);
                diff = nums[l]-nums[r];
                maxWid = max(maxWid, r-l);
                r += 1;
            }
            l += 1;
            if(l >= nums.size())break;
            s -= (nums[l-1]-nums[l])*(r-l);
            diff = (l != r)? nums[l]-nums[r-1]:0;
        }
        return maxWid+1;
    }
};
