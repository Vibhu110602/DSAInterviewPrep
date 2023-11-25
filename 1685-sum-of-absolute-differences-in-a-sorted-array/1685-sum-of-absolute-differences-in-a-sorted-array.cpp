class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> suf(n+1,nums[nums.size()-1]);
        suf[n]=0;
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+nums[i];
        }
        vector<int> ans(n,0);
        int prev=0;
        for(int i=0;i<n;i++){
            prev+=nums[i];
            cout<<((i+1)*nums[i]-prev)<<" "<<(suf[i+1]-(n-i-1)*nums[i])<<endl;
            ans[i]=((i+1)*nums[i]-prev)+(suf[i+1]-(n-i-1)*nums[i]);
        }
        
        return ans;
    }
};