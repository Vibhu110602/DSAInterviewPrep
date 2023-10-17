class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mp;
        for(int i=0;i<nums.size();i++)mp.insert(nums[i]);
        int ans=0,curr=0;
        int prev=-1;
        for(auto it:mp){
            if(it==prev+1){
                curr++;
                prev=it;
            }else{
                
                prev=it;
                curr=1;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};