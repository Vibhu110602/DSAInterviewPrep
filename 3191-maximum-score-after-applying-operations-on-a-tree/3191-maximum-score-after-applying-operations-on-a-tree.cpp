class Solution {
public:
    long long helper(int node,vector<int> adj[],vector<int>& vis,vector<int>& values){
        if(adj[node].size()==1 && node!=0)return values[node];
        long long curr=0;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                curr+=helper(it,adj,vis,values);
            }
        }
        return min(curr,(long long)values[node]);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans=0;
        for(auto it:values)ans+=it;
        vector<int> vis(n,0);
        return ans-helper(0,adj,vis,values);
    }
};