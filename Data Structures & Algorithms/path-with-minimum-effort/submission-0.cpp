class Solution {
    int dc[4]={-1,0,1,0};
    int dr[4]={0,-1,0,1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size(),col=heights[0].size();
        vector<vector<int>> dist (row,vector<int>(col,INT_MAX));
        dist[0][0]=0;
        priority_queue <vector<int>,vector<vector<int>>, greater<>> pq;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto curr=pq.top();
            int diff=curr[0], r=curr[1], c=curr[2];
            pq.pop();
            if(r==row-1 && c==col-1) return diff;
            if(dist[r][c]<diff) continue;

            for(int k=0;k<4;k++){
                int x=r+dr[k];
                int y=c+dc[k];
                if(x<0 || y<0 || x>=row || y>=col) continue;
                int newDiff=max(diff,abs(heights[r][c]-heights[x][y]));
                if(newDiff<dist[x][y]){
                     dist[x][y]=newDiff;
                    pq.push({newDiff,x,y});
                }
            }
        }
        return 0;
    }
};