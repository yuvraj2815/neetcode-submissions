class Solution {
    int dr[4]={0,-1,0,1};
    int dc[4]={-1,0,1,0};
public:
    void dfs(int row,int col,vector<vector<bool>>& ocean,vector<vector<int>>& heights){
        ocean[row][col]=true;
        for(int k=0;k<4;k++){
            int r=row+dr[k];
            int c=col+dc[k];
            if(r>=0 && c>=0 && r<heights.size() && c<heights[0].size() && !ocean[r][c] && heights[r][c]>=heights[row][col]) dfs(r,c,ocean,heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>> pac(row,vector<bool>(col,false));
        vector<vector<bool>>alt(row,vector<bool>(col,false));

        for(int c=0;c<col;c++){
            dfs(0,c,pac,heights);
            dfs(row-1,c,alt,heights);
        }

        for(int r=0;r<row;r++){
            dfs(r,0,pac,heights);
            dfs(r,col-1,alt,heights);
        }

        vector<vector<int>> res;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(pac[r][c] && alt[r][c]) res.push_back({r,c});
            }
        }
        return res;
    }
};
