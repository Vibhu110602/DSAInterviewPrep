class Solution {
    int mod=1e9+7;
public:
    int countHomogenous(string s) {
        unordered_map<char,char> mp;
        int i=0,j=0;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()>1){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            ans=(ans+(j-i+1))%mod;
            j++;
        }
        return ans;
    }
};