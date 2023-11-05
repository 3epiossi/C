class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size()-1)
            return *max_element(arr.begin(), arr.end());
        for(auto cur = arr.begin(); cur != arr.end(); ++cur){
            if(*max_element(arr.begin(), cur) <= *cur){
                int cnt = 0;
                vector<int>::iterator back;
                for(back = cur; back != arr.end() && *back <= *cur; ++back)
                    ++cnt;
                if (back != arr.end()){
                    if(cnt-1+(cur!=arr.begin()) < k)
                        continue;
                    else
                        return *cur;
                }
                else
                    return *cur;
            }
            else
                continue;

        }
        return *max_element(arr.begin(), arr.end());
    }
};
