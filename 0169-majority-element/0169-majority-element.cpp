class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el=nums[0],fr=0;
        for(int i=0;i<n;i++){
            if(fr==0){
                el=nums[i];
                fr=1;
            }else if(el==nums[i]){
                fr++;
            }else fr--;
        }
        fr=0;
        for(int i=0;i<n;i++){
            if(el==nums[i])fr++;
        }
        return fr>(n/2)?el:-1;
    }
};