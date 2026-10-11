class Solution {
    int drow[4]={0,-1,0,1};
    int dcol[4]={-1,0,1,0};
public:
    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]=='0') return;
        grid[r][c]='0';
        for(int k=0;k<4;k++){
            int x=r+drow[k];
            int y=c+dcol[k];
            dfs(grid,x,y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int island=0;

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]=='1'){
                    dfs(grid,r,c);
                    island++;
                }
            }
        }
        return island;
    }
};
