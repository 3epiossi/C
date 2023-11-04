class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(auto i = left.begin(); i != left.end(); ++i){
            res = max(res, abs(0 - *i));
        }
        for(auto i = right.begin(); i != right.end(); ++i){
            res = max(res, abs(n - *i));
        }
        return res;
    }
};
