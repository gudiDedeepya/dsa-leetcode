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

 void sumi(TreeNode* root,vector<int>& ans,int value){
    if(root==NULL) return;
    if(root->left==NULL&&root->right==NULL) {ans.push_back(value); return;
    }

    if(root->left){
        //value=value*10+root->left->val;
        sumi(root->left,ans,value*10+root->left->val);

    }
    if(root->right){
        //value=value*10+root->right->val;
        sumi(root->right,ans,value*10+root->right->val);
    }

 }
    int sumNumbers(TreeNode* root) {
        
        vector<int>ans;
        if(root==NULL) return 0;
        sumi(root,ans,root->val);

        return accumulate(ans.begin(),ans.end(),0);


    }
};