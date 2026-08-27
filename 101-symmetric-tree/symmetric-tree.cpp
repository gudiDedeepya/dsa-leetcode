/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
bool isi(TreeNode*lefti,TreeNode*righti){
     if(lefti==NULL&&righti==NULL) return true;
    else if(lefti==NULL&&righti!=NULL) return false;
    else if(lefti!=NULL&&righti==NULL) return false;
    else if(lefti->val!=righti->val) return false;
    bool l=isi(lefti->left,righti->right);
    bool r=isi(lefti->right,righti->left);
    return l&&r;

}
    bool isSymmetric(TreeNode* root) {
        return isi(root->left,root->right);
    }
};