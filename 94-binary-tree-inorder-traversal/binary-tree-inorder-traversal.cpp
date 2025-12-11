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
void dfs(vector<int>&inor,TreeNode* root){
     if(root==NULL)
     return;
      dfs(inor,root->left);
     inor.push_back(root->val);
     dfs(inor,root->right);
}
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>inor;
         dfs(inor,root);
         return inor;
    }
};