/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> que;
        if(root)que.push(root);
        while(!que.empty()){
            int maxi=INT_MIN;
            int size=que.size();
            for(int i=0;i<size;i++){
                auto node=que.front();
                que.pop();
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
                maxi=max(maxi,node->val);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};