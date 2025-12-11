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
void dfs(vector<int>&preor,TreeNode* root){
     if(root==NULL)
     return;
     preor.push_back(root->val);
     dfs(preor,root->left);
     dfs(preor,root->right);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preor;
         dfs(preor,root);
         return preor;
    }
};