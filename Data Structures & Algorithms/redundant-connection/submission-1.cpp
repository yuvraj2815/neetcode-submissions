class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);

        for(auto &ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
            indegree[ed[0]]++;
            indegree[ed[1]]++;
        }

        queue<int> q;
        for(int i=0;i<=n;i++){
            if(indegree[i]==1) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            indegree[node]--;
            for(auto ad:adj[node]){
                indegree[ad]--;
                if(indegree[ad]==1) q.push(ad);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(indegree[edges[i][0]]>0 && indegree[edges[i][1]]>0) return{edges[i][0],edges[i][1]};
        }   
        return {};
    }
};
