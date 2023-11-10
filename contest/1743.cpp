class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int> > adj;
        for (const auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        int head;
        for(const auto& i : adj){
            if(i.second.size() == 1){
                head = i.first;
                break;
            }
        }
        vector<int>res;
        res.reserve(adjacentPairs.size()+1);
        res.push_back(head);
        res.push_back(adj[head][0]);
        int cur;
        while(true){
            cur = res[res.size()-1];
            if(adj[cur].size() == 2){
                if(adj[cur][0] != res[res.size()-2]){
                    res.push_back(adj[cur][0]);
                } 
                else{
                    res.push_back(adj[cur][1]);
                }
            } 
            else{
                break;
            }
        }
        return res;
    }
};
