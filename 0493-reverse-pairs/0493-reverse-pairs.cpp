class Solution {
public:
    int count(int i,int mid,int j,vector<int>& nums) {
        int ans=0;
        int right=mid+1;
        for(int k=i;k<=mid;k++){
            while(right<=j && (long long)nums[k]>(long long)2*(long long)nums[right])right++;
            ans+=(right-(mid+1));
        }
        return ans;
    }
    void merge(int i,int mid,int j,vector<int>& nums) {
        int left=i,right=mid+1;
        vector<int> arr;
        while(left<=mid && right<=j){
            if(nums[left]<nums[right]){
                arr.push_back(nums[left++]);
            }else{
                arr.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            arr.push_back(nums[left++]);
        }
        while(right<=j){
            arr.push_back(nums[right++]);
        }
        for(int k=i;k<=j;k++){
            nums[k]=arr[k-i];
        }
    }
    int mergeSort(int i,int j,vector<int>& nums) {
        if(i>=j)return 0;
        int ans=0;
        int mid=(i+j)/2;
        ans+=mergeSort(i,mid,nums);
        ans+=mergeSort(mid+1,j,nums);
        ans+=count(i,mid,j,nums);
        merge(i,mid,j,nums);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(0,n-1,nums);
    }
};