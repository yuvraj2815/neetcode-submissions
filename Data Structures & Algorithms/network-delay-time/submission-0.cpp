class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map <int, vector<pair<int,int>>> edges;

        for(auto time:times){
            edges[time[0]].push_back({time[1],time[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        unordered_set <int> vst;
        int t=0;
        while(!pq.empty()){
            auto curr=pq.top();
            int w1=curr.first;
            int n1=curr.second;
            pq.pop();
            if(vst.count(n1)) continue;
            vst.insert(n1);
            t=w1;
            if(edges.count(n1)){
                for(auto nei:edges[n1]){
                    int n2=nei.first,w2=nei.second;
                    if(!vst.count(n2)) pq.push({w1+w2,n2});
                }
            }
        }
        return vst.size()==n ?t:-1;
    }
};
