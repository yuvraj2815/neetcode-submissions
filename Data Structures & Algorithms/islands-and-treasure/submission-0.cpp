class Solution {
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,-1,0,1};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue <pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int x=r+drow[k];
                int y=c+dcol[k];
                if(x<0 || y<0 || x>=row || y>=col || grid[x][y]!=INT_MAX) continue;

                grid[x][y]=grid[r][c]+1;
                q.push({x,y});
            }
        }
    }
};
