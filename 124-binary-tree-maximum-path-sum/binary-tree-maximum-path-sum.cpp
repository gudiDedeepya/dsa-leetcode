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
     int path=INT_MIN;
    int paths(TreeNode* root){
            if(root==NULL){
                return 0;
            }
            int left=paths(root->left);
            if(left<0) left=0;
            int right=paths(root->right);
            if(right<0) right=0;

            path=max(path,left+right+root->val);



            
        return root->val+max(left,right);
           
    }
    int maxPathSum(TreeNode* root) {
         paths(root);
         return path;
    }
};