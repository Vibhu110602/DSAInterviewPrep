class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double> dis(n);
        for(int i=0;i<n;i++){
            dis[i]=(double)((double)dist[i]/speed[i]);
        }
        sort(begin(dis),end(dis));
        int ans=1,time=1;
        for(int i=1;i<n;i++){
            cout<<dis[i]<<" ";
            if(dis[i]<=time)break;
            time++;
            ans++;
        }
        return ans;
    }
};