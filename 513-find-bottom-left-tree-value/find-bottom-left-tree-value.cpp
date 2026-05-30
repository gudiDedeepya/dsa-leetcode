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
    int findBottomLeftValue(TreeNode* root) {
          queue<TreeNode*>g;
        g.push(root);
        int left=root->val;
        while(!g.empty()){
        int size=g.size();
         left=g.front()->val;
        for(int i=0;i<size;i++){
            TreeNode*node=g.front();
            g.pop();
            if(node->left!=NULL) { 
            g.push(node->left);
            }
            if(node->right!=NULL) g.push(node->right);
        }
        }
        return left;
    }
};