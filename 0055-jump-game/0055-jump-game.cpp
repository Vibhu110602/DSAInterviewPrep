class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(i>maxi)return false;
            if(maxi>=n-1)return true;
            maxi=max(maxi,nums[i]+i);
        }
        return false;
    }
};