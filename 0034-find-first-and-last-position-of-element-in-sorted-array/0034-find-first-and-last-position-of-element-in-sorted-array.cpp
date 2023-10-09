class Solution {
public:
    int first(int l,int h,int target,vector<int>& nums) {
        int ind=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(target==nums[mid]){
                ind=mid;
                h=mid-1;
            }
            else if(target>nums[mid])l=mid+1;
            else h=mid-1;
        }
        return ind;
    }
    int last(int l,int h,int target,vector<int>& nums) {
        int ind=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(target==nums[mid]){
                ind=mid;
                l=mid+1;
            }
            else if(target>nums[mid])l=mid+1;
            else h=mid-1;
        }
        return ind;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> res;
        res.push_back(first(0,n-1,target,nums));
        res.push_back(last(0,n-1,target,nums));
        return res;
    }
};