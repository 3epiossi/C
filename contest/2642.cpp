class Graph {
private:
map<int, vector<pair<int, int> > > adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        for (auto edge : edges)
            adj[edge[0]].push_back({edge[2], edge[1]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[2], edge[1]});
    }
    
    int shortestPath(int node1, int node2) {
            priority_queue<tuple<int, int>, vector<tuple<int, int> >, greater<> > next;
            tuple<int, int> start = {0, node1};
            next.push({0, node1});
            int score[100];
            for(int i = 0; i < 100; ++i){
                score[i] = INT_MAX;
            }
            while(!next.empty()){
                tuple<int, int> now = next.top();
                int cost = std::get<0>(now);
                int cur = std::get<1>(now);
                next.pop();
                if(score[cur] <= cost)
                    continue;
                score[cur] = cost;
                if(cur == node2){
                    return score[cur];
                }
                for(const auto& son : adj[cur]){
                    tuple<int, int> gonext = {cost+son.first, son.second};
                    next.push(gonext);
                }
            }
            return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
