class Solution {
public:
    int has(string str,char a,int& ans) {
        int cnt=0;
        for(auto ch:str){
            if(ch==a){
                cnt++;ans++;
            }
        }
        return cnt;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0,dis=0;
        int p=0,g=0,m=0;
        for(int i=0;i<garbage.size();i++){
            string str=garbage[i];
            if(has(str,'P',ans)){
                p=dis;
            }
            if(has(str,'G',ans)){
                g=dis;
            }
            if(has(str,'M',ans)){
                m=dis;
            }
            if(i<garbage.size()-1)dis+=travel[i];
        }

        return ans+g+m+p;
    }
};