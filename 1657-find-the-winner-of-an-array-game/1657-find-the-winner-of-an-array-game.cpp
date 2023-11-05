class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=*max_element(begin(arr),end(arr));
        if(k>=n)return maxi;
        int ans=arr[0],cnt=0;
        for(int i=1;i<n;i++){
            if(arr[i]>ans){
                ans=arr[i];
                cnt=1;
            }else{
                cnt++;
            }
            if(cnt==k || ans==maxi)return ans;
        }
        return 0;
    }
};