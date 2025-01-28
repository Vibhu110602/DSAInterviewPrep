class Solution {
public:
    int ans=0;
    int curr;
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};
    void dfs(int i,int j,vector<vector<int>>& grid){
        curr+=grid[i][j];
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int ni=i+row[k];
            int nj=j+col[k];
            if(ni>=0 && nj>=0 &&ni<grid.size() && nj<grid[0].size() && grid[ni][nj]){
                dfs(ni,nj,grid);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    curr=0;
                    dfs(i,j,grid);
                    ans=max(curr,ans);
                }
            }
        }
        return ans;
    }
};