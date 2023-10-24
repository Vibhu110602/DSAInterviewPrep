class Solution {
public:
    int change(int n){
        int ans=0;
        while(n){
            int a=n%10;
            ans+=a*a;
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int cnt=0;
        while(cnt<1000){
            int num=change(n);
            if(num==1)return true;
            n=num;
            cnt++;
        }
        return false;
    }
};