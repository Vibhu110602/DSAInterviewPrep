class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(auto it:nums)st.insert(it);
        nums.resize(0);
        for(auto it:st)nums.push_back(it);
        int ans=n;
        for(int i=0;i<nums.size();i++){
            int first=nums[i];
            int last=first+n-1;
            vector<int>::iterator upper=upper_bound(nums.begin(),nums.end(),last);
            int len=upper-nums.begin();
            ans=min(ans,n-(len-i));
        }
        return ans;
    }
};