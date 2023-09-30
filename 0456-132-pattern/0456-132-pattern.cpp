class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int end=INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            if( nums[i]<end ) return true;
            else while(!st.empty() && nums[i]>st.top() ){ 
              end=st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
    }
};