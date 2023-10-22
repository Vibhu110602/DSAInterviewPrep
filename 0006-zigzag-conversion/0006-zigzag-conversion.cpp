class Solution {
public:
    string convert(string s, int rows) {
        int n=s.size();
        if(rows==1)return s;
        vector<string> str(rows,"");
        int col=0;int down=-1;
        for(int i=0;i<n;i++){
            if(col==0 || col==rows-1)down*=-1;
            str[col]+=s[i];
            if(down==1)col++;
            else col--;
        }
        string ans="";
        for(auto it:str)ans+=it;
        return ans;
    }
};