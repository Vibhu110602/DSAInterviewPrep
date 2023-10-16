class Solution {
public:
    int comb(int n,int r)
    {
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans=ans*(n-i+1)/i;
        }
        return ans;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i=0;i<=rowIndex;i++){
            ans.push_back(comb(rowIndex,i));
        }
        return ans;
    }
};