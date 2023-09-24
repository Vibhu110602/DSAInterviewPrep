class Solution {
public:
    double helper(int left,int i,int j,vector<vector<double>>& dp){
        if(i<0 || j<0 || i<j)return 0.0;
        if(i==0 && j==0)return left;
        if(dp[i][j]!=-1)return dp[i][j];
        double up_left=max(0.0,(helper(left,i-1,j-1,dp)-1)/2.0);
        double up_right=max(0.0,(helper(left,i-1,j,dp)-1)/2.0);
        return dp[i][j]=up_left+up_right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101,vector<double>(101,-1));
        return min(1.0,helper(poured,query_row,query_glass,dp));
    }
};