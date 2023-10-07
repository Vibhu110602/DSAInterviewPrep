class Solution {
    int dp[51][51][101];
    int mod=1e9+7;
public:
    int solve(int i,int search,int maxi,int &n,int &m,int &k){
        if(i>=n){
            if(search==k)return 1;
            return 0;
        }
        if(dp[i][search][maxi]!=-1)return dp[i][search][maxi];
        int ans=0;
        for(int j=1;j<=m;j++){
            if(j>maxi)ans=(ans+solve(i+1,search+1,j,n,m,k))%mod;
            else ans=(ans+solve(i+1,search,maxi,n,m,k))%mod;
        }
        return dp[i][search][maxi]=ans;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,m,k);
    }
};