class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        map<int, vector<int> > stop2Bus;
        for(int i = 0; i < routes.size(); ++i){
            for(auto stop : routes[i]){
                stop2Bus[stop].push_back(i);
            }
        }
        queue<int> stops;
        stops.push(source);
        set<int> pas;
        int cntBus = 0;
        while(!stops.empty()){
            for(int i = stops.size()-1; i > -1; --i){
                int curStop = stops.front();
                if(curStop == target){
                    return cntBus;
                }
                stops.pop();
                for(auto bus: stop2Bus[curStop]){
                    if(pas.find(bus) != pas.end()){
                        continue;
                    }
                    pas.insert(bus);
                    for(auto stop: routes[bus]){
                        stops.push(stop);
                    }
                }
            }
            cntBus += 1;
        }
        return -1;
    }
};
