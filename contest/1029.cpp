class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > hq;
        priority_queue<pair<int, int> > hq;
        for(int i = 0; i < costs.size(); ++i){
            pair<int, int> amore = {costs[i][0]-costs[i][1], i};
            hq.push(amore);
            if(hq.size() > costs.size()/2){
                hq.pop();
            }
        }
        int res = 0;
        int visit[100] = {};
        while(!hq.empty()){
            res += costs[hq.top().second][0];
            visit[hq.top().second] = 1;
            hq.pop();
        }
        for(int i = 0; i < 100; ++i){
            if(i < costs.size() and !visit[i]){
                res += costs[i][1];
            }
        }
        return res;
    }
};
