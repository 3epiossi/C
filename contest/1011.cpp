class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = 25000001;
        int l = 0;
        while(l <= r){
            int cap = (l+r)/2;
            int count = 0;
            for(int ll = 0; ll < weights.size();){
                int rr = ll;
                int nowCap = 0;
                if(weights[rr] > cap){
                    count = INT_MAX;
                    break;
                }
                for(; rr < weights.size() and nowCap+weights[rr] <= cap;
                      nowCap += weights[rr], ++rr);
                ll = rr;
                ++count;
            }
            if(count <= days){
                r = cap-1;
            }
            else{
                l = cap+1;
            }
        }
        return l;
    }
};
