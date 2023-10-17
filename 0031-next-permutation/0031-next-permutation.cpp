class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(arr.begin(),arr.end());
        }else{
            for(int j=n-1;j>=0;j--){
                if(arr[j]>arr[idx]){
                    swap(arr[idx],arr[j]);
                    break;
                }
            }
            reverse(arr.begin()+idx+1,arr.end());
        }
    }
};