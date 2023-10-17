class Solution {
public:
    double myPow(double x, long long n) {
        bool neg=false;
        if(n<0){
            neg=true;
            n=-n;
        }
        double ans=1;
        while(n){
            if(n%2==0){
                x=x*x;
                n=n/2;
            }else{
                ans=ans*x;
                n--;
            }
        }
        if(neg)return 1/ans;
        return ans;
    }
};