class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> lastIndex;
        unordered_map<char,bool> vis;
        for(int i=0;i<s.size();i++){
            lastIndex[s[i]]=i;
            vis[s[i]]=false;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(vis[s[i]])continue;
            while(st.size()>0 && st.top()>s[i] && i<lastIndex[st.top()]){
                vis[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]]=true;
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};