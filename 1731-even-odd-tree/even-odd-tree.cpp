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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>g;
        g.push(root);
        int cnt=0;
        while(!g.empty()){
        int maxi=0;
        int mini=INT_MAX;

        int size=g.size();
        vector<int>level;
        for(int i=0;i<size;i++){
           
            TreeNode*node=g.front();
             if(cnt%2==0){
                if(node->val%2!=0&&node->val>maxi){
                    maxi=node->val;
                }
                else{
                    return false;
                }
            }
            else{
                if(node->val%2==0&&node->val<mini){
                    mini=node->val;
                }
                else{
                    return false;
                }
            }
            g.pop();
            if(node->left!=NULL) g.push(node->left);
            if(node->right!=NULL) g.push(node->right);
        }
        cnt++;
        }
        return true;
    }
};