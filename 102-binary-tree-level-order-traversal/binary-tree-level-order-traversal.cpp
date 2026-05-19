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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>g;
        g.push(root);
        while(!g.empty()){
        int size=g.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode*node=g.front();
            g.pop();
            if(node->left!=NULL) g.push(node->left);
            if(node->right!=NULL) g.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
        }
        return ans;
    }
};