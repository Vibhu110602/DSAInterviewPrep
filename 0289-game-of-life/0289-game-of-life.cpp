class Solution {
    int row[8]={-1,-1,0,1,1,1,0,-1};
    int col[8]={0,1,1,1,0,-1,-1,-1};
public:
    int calculate(int r,int c,vector<vector<int>>& board){
        int ans=0;
        for(int i=0;i<8;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && board[nr][nc] && board[nr][nc]!=-2) {
                ans++;
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]){
                    int pop=calculate(i,j,board);
                    if(pop<2 || pop>3)board[i][j]=-1;
                }else{
                    int pop=calculate(i,j,board);
                    if(pop==3)board[i][j]=-2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-1)board[i][j]=0;
                else if(board[i][j]==-2)board[i][j]=1;
            }
        }
    }
};