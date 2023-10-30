class Solution {
public:
    int comb(int n,int r) {
        int ans=1;
        for(int i=0;i<r;i++){
            ans=ans*(n-i)/(i+1);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i=0;i<numRows;i++){
            vector<int> a;
            for(int j=0;j<=i;j++){
                a.push_back(comb(i,j));
            }
            triangle.push_back(a);
        }
        return triangle;
    }
};