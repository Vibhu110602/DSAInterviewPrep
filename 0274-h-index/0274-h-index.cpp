class Solution {
public:
    bool check(int mid,vector<int>& cite) {
        int n=cite.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(cite[i]>=mid)ans++;
        }
        return ans>=mid;
    }
    int hIndex(vector<int>& cite) {
        int n=cite.size();
        int i=0,j=n;
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(check(mid,cite)){
                ans=mid;
                i=mid+1;
            }else j=mid-1;
        }
        return ans;
    }
};