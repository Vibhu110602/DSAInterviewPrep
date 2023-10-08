class Solution {
    int dp[501][501];
public:
    int solve(int i,int j,int n,int m,vector<int>& nums1, vector<int>& nums2){
        if(i>=n || j>=m)return INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=-1e8;
        ans=max(ans,nums1[i]*nums2[j]+max(0,solve(i+1,j+1,n,m,nums1,nums2)));
        ans=max(ans,solve(i,j+1,n,m,nums1,nums2));
        ans=max(ans,solve(i+1,j,n,m,nums1,nums2));
        return dp[i][j]=ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums1.size(),nums2.size(),nums1,nums2);
    }
};