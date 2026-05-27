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
 vector<int> rightSideView(TreeNode* root) {
         vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>g;
        g.push(root);
        while(!g.empty()){
        int size=g.size();
        for(int i=0;i<size;i++){

            TreeNode*node=g.front();
            if(i==size-1) ans.push_back(node->val);
            g.pop();
            if(node->left!=NULL) g.push(node->left);
            if(node->right!=NULL) g.push(node->right);
            
        }
        }
        return ans;
    }
};