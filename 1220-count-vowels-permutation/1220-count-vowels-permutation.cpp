class Solution {
    const int mod = 1e9 + 7;

public:
    int helper(int i, int n, int j, vector<vector<long long>>& dp) {
        if (i == n) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        long long ans = 0;

        if (j == 1)
            ans = (ans + helper(i + 1, n, 0, dp) + helper(i + 1, n, 2, dp)) % mod;
        else if (j == 0)
            ans = (ans + helper(i + 1, n, 4, dp) + helper(i + 1, n, 1, dp) + helper(i + 1, n, 2, dp)) % mod;
        else if (j == 2)
            ans = (ans + helper(i + 1, n, 1, dp) + helper(i + 1, n, 3, dp)) % mod;
        else if (j == 4)
            ans = (ans + helper(i + 1, n, 3, dp) + helper(i + 1, n, 2, dp)) % mod;
        else if (j == 3)
            ans = (ans + helper(i + 1, n, 2, dp)) % mod;

        return dp[i][j] = ans;
    }

    int countVowelPermutation(int n) {
        int ans = 0;
        vector<vector<long long> > dp(n, vector<long long>(5, -1));
        for (int i = 0; i < 5; i++) {
            ans = (ans + helper(1, n, i, dp)) % mod;
        }
        return ans;
    }
};
