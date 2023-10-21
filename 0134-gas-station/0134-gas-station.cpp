class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        int total=0,curr=0;
        int ans=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            curr+=gas[i]-cost[i];
            if(curr<0){
                curr=0;
                ans=i+1;
            }
        }
        return (total>=0)?ans:-1;
    }
};