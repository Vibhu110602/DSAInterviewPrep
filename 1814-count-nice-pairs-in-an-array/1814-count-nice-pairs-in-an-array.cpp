class Solution {
    int mod=1e9+7;
public:
    int rev(int num) {
        int rev=0;
        while(num>0) {
            rev=rev*10+num%10;
            num/=10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i]-rev(nums[i]);
            ans=(ans+mp[curr])%mod;
            mp[curr]++;
        }
        return ans;
    }
};