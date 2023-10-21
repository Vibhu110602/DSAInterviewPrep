class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> arr;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            arr.push_back(val);
            mp[val]=arr.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        int idx=mp[val];
        int last=arr.back();
        arr[idx]=last;
        mp[last]=idx;
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int r=rand()%arr.size();
        return arr[r];
    }
};
