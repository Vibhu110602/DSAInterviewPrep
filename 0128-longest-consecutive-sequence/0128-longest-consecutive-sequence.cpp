class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num:nums)st.insert(num);
        int ans=0,curr=0;
        for(auto num:st){
            if(st.find(num-1)!=st.end())continue;
            curr=1;
            int x=num+1;
            while(st.find(x)!=st.end()){
                curr++;
                x++;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};