class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++) {   
            arr[i]=nums[i];
        }
        int ans=nums[0];
        priority_queue<pair<int,int>> que;
        que.push({arr[0],0});
        cout<<arr[0]<<" ";
        for(int i=1;i<n;i++){
            while(!que.empty() && i-que.top().second>k){
                que.pop();
            } 
            arr[i]=max(arr[i],que.top().first+arr[i]);
            cout<<arr[i]<<" ";
            que.push({arr[i],i});
            ans=max(ans,arr[i]);
        }
        return ans;
    }
};