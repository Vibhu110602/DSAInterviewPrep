class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                char num=board[i][j];
                for(int k=0;k<9;k++){
                    if(k!=j && board[i][k]==num)return false;
                    if(i!=k && board[k][j]==num)return false;
                    if((3*(i/3)+k/3)!=i && (3*(j/3)+k%3)!=j && board[3*(i/3)+k/3][3*(j/3)+k%3]==num)return false;
                }
            }
        }
        return true;
    }
};