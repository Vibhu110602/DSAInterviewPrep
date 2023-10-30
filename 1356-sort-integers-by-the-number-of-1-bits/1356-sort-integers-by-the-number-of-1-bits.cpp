class Solution {
public:
    int count(int x){
        int ans=0;
        while(x){
            ans+=x&1;
            x=x>>1;
        }
        return ans;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr),end(arr),[=](int& a,int& b){
            int ca=count(a);
            int cb=count(b);
            if(ca==cb)return a<=b;
            return ca<cb;
        });
        return arr;
    }
};