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
bool inorder(TreeNode* temp1,TreeNode* temp2) {

    if(temp1 == NULL&&temp2!=NULL) return false;
    if(temp1 != NULL&&temp2==NULL) return false;
    if(temp1==NULL&&temp2==NULL) return true;
     if(temp1->val!=temp2->val) return false;

    bool flag1=inorder(temp1->left,temp2->right);
   

    bool flag2=inorder(temp1->right,temp2->left);

    if(flag1&&flag2) return true;
    else 
     return false;
}
    bool isSymmetric(TreeNode* root) {
        TreeNode*temp1=root->left;
         TreeNode*temp2=root->right;
         if(root==NULL) return true;
         bool flag=inorder(temp1,temp2);
        return flag;
    }
};