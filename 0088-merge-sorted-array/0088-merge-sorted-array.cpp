class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[i+m]=nums2[i];
        }
        int len=(n+m);
        int gap=len/2;
        while(gap){
            for(int i=0;i+gap<len;i++){
                if(nums1[i]>nums1[i+gap])swap(nums1[i],nums1[i+gap]);
            }
            gap= (gap==1)?0:(gap/2)+(gap%2);
        }
    }
};