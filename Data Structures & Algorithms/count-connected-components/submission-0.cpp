class Solution {
private:
    void dfs(vector<vector<int>>& adj,vector<bool>& vst,int node){
        vst[node]=true;
        for(auto ad:adj[node]){
            if(!vst[ad]) dfs(adj,vst,ad);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vst(n,false);

        for(auto &ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);           
        }
        int res=0;
        for(int i=0;i<n;++i){
            if(!vst[i]) {
                dfs(adj,vst,i);
                res++;
            }
        }
        return res;
    }
};
