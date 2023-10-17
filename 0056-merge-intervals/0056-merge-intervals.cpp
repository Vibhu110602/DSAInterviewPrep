class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        });
        for(int i=0;i<intervals.size();i++){
            if(!ans.size())ans.push_back(intervals[i]);
            else{
                if(intervals[i][0]<=ans[ans.size()-1][1]){
                    ans[ans.size()-1][0]=min(ans[ans.size()-1][0],intervals[i][0]);
                    ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
                }else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};