class Solution {
public:
    int ncr(int n,int r) {
        int ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-i+1)/(i);
        }
        return ans;
    }
    vector<vector<int>> generate(int r) {
        vector<vector<int>> ans;
        for(int i=0;i<r;i++){
            vector<int> curr;
            for(int j=0;j<=i;j++){
                curr.push_back(ncr(i,j));
            }
            ans.push_back(curr);
        }
        return ans;
    }
};