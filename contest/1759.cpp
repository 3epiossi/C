#define Mod 1000000007
class Solution {
public:
    int countHomogenous(string s) {
        int count = 0;
        long long  l = 0, r = 0;
        while(l < s.size()){
            for(r = l; r < s.size() and s[r] == s[l]; ++r);
            count += ((r-l)*(r-l+1)/2) % Mod;
            l = r;
        }
        return count;
    }
};
