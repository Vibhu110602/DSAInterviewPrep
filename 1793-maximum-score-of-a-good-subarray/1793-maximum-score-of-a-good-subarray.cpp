class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=k,j=k;
        int result=nums[k],mini=nums[k];
        while(i>0 || j<n-1){
            int left= i>0?nums[i-1]:0;
            int right= j<n-1?nums[j+1]:0;
            if(left<right){
                j++;
                mini=min(mini,nums[j]);
            }else{
                i--;
                mini=min(mini,nums[i]);
            }
            result=max(result,mini*(j-i+1));
        }
        return result;
    }
};