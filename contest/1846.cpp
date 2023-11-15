class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end(), less<int>() );
        int mx = 0;
        for(auto& cur: arr){
            mx = (cur-mx != 0)? mx+1: mx;
        }
        return mx;
    }
};
