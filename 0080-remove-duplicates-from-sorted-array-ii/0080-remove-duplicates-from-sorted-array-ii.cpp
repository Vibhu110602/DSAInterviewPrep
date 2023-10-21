class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int k=0;k<n;k++){
            if(i==0 || i==1 || nums[i-2]!=nums[k]){
                nums[i]=nums[k];
                i++;
            }
        }
        return i;
    }
};
