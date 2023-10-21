class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int prod=1,prod1=1,cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]){
                prod1=prod1*nums[i];
                prod=prod*nums[i];
            }else{
                prod=prod*nums[i];
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]){
                ans[i]=prod/nums[i];
            }else{
                if(cnt==1)ans[i]=prod1;
            }
        }
        return ans;
    }
};