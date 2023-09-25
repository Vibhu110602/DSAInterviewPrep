class Solution {
public:
    char findTheDifference(string s, string t) {
        char a=0;
        for(int i=0;i<s.size();i++)
            a=a^s[i];
        for(int i=0;i<t.size();i++)
            a=a^t[i];
        return a;
    }
};