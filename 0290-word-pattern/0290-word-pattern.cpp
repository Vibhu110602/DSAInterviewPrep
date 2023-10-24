class Solution {
public:
    bool wordPattern(string pat, string s) {
        istringstream ss(s);
        string word;
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        int i=0;
        while(i<pat.size() && ss>>word){
            if(mp1.count(pat[i]) && mp1[pat[i]]!=word)return false;
            if(mp2.count(word) && mp2[word]!=pat[i])return false;
            mp1[pat[i]]=word;
            mp2[word]=pat[i];
            i++;
        }
        if(i<pat.size() || ss>>word)return false;
        return true;
    }
};