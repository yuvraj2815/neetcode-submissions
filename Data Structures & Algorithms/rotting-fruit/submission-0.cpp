class Solution {
    int drow[4]={0,-1,0,1};
    int dcol[4]={-1,0,1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<int,int>> q;
        int fresh=0;
        int time=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2)q.push({i,j}); 
            }
        }
        while(fresh>0 && !q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int x=r+drow[k];
                    int y=c+dcol[k];
                    if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh==0?time:-1;
    }
};
