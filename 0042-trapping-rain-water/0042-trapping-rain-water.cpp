class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pre(n,height[0]),suf(n,height[n-1]);
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(0,min(suf[i],pre[i])-height[i]);
        }
        return ans;
    }
};


