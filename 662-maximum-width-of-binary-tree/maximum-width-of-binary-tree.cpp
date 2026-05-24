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

    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int width=0;
        while(!q.empty()){
            long long  left=q.front().second;
            long long  right=0;
            int size=q.size();
            long long mini = q.front().second;
            for(int i=0;i<size;i++){
                 TreeNode* node=q.front().first;
                 long long idx = q.front().second - mini;
                 if(i==size-1){right=q.front().second;}
                 q.pop();
                 if(node->left!=NULL)q.push({node->left,2*idx+1});
                 if(node->right!=NULL)q.push({node->right,2*idx+2});
                 
            }
            width=max((long long)width,right-left+1);
        }
        return width;
    }
};