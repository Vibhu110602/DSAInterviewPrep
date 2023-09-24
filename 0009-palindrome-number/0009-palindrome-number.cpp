class Solution {
public:
    bool isPalindrome(int x) {
        string a=to_string(x);
        for(int i=0;i<a.size()/2;i++)
        {
            if(a[i]!=a[a.size()-1-i])
                return false;
        }
        return true;
    }
};