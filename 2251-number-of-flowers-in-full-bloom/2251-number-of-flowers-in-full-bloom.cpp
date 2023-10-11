class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        vector<int> ans(people.size());
        vector<int> start(n),endd(n);
        for(int i=0;i<n;i++){
            start[i]=flowers[i][0];
            endd[i]=flowers[i][1];
        }
        sort(begin(start),end(start));
        sort(begin(endd),end(endd));
        for(int i=0;i<people.size();i++){
            int curr=people[i];
            int bloom=upper_bound(begin(start),end(start),curr)-begin(start);
            int die=lower_bound(begin(endd),end(endd),curr)-begin(endd);
            ans[i]=bloom-die;
        }
        return ans;
    }
};