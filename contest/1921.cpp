class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
       vector<int> time(dist.size());
       int i;
       for(i = 0; i < dist.size(); ++i){
           time[i] = dist[i]/speed[i] + (dist[i]%speed[i] != 0);
       }
       sort(time.begin(), time.end());
       for(i = 0; i < time.size() and i < time[i]; ++i);
       return i;
    }
};
