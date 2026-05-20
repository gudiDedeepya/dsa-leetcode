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
    
    bool same(TreeNode* p, TreeNode* q){
        bool left,right;
         if(p==NULL&&q==NULL) return true;
        else if(p==NULL&&q!=NULL) return false;
        else if(p!=NULL&&q==NULL) return false;
        else if(p->val!=q->val) return false;
        else {
            left=same(p->left,q->left);
            right=same(p->right,q->right);
        }
        return  left && right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       
     bool isi=same(p,q);
     return isi;

        
    }
};