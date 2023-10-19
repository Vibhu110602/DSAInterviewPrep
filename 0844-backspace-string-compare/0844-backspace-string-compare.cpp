class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!str.empty())str.pop_back();
            }
            else str.push_back(s[i]);
        }
        string str1="";
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!str1.empty())str1.pop_back();
            }
            else str1.push_back(t[i]);
        }
        cout<<str<<str1;
        return str==str1;
    }
};