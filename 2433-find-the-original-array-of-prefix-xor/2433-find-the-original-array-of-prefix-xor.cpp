class Solution {
public:
    vector<int> findArray(vector<int>& pre) {
        int n=pre.size();
        vector<int> ans(n,pre[0]);
        int xr=pre[0];
        for(int i=1;i<n;i++){
            ans[i]=xr^pre[i];
            xr=xr^ans[i];
        }
        return ans;
    }
};