class Solution {
public:
    int mod=1e9+7;
    int dp[510][510];
    int helper(int i,int step,int n){
        if(step==0)return i==0;
        if(dp[i][step]!=-1)return dp[i][step];
        long long stay=helper(i,step-1,n);
        if(i-1>=0)stay+=helper(i-1,step-1,n);
        if(i+1<n)stay+=helper(i+1,step-1,n);
        return dp[i][step]=(stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return helper(0,steps,arrLen);
    }
};