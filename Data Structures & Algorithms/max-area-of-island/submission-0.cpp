class Solution {
    int drow[4]={0,-1,0,1};
    int dcol[4]={-1,0,1,0};
public:
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0) return 0;
        grid[r][c]=0;
        int res=1;
        for(int k=0;k<4;k++){
            int x=r+drow[k];
            int y=c+dcol[k];
            res +=dfs(grid,x,y);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int area=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1)area=max(area,dfs(grid,r,c));
            }
        }
        return area;
    }
};
