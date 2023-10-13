class Solution {
public:
    int helper(int i,vector<int>& cost,vector<int>& dp) {
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int one=cost[i]+helper(i+1,cost,dp);
        int two=cost[i]+helper(i+2,cost,dp);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
       return min(helper(0,cost,dp),helper(1,cost,dp)); 
    }
};