/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*lca;
        TreeNode*temp=root;
        while(temp!=NULL){
            if(temp->val<p->val&&temp->val>q->val||temp->val<q->val&&temp->val>p->val){
            lca=temp;
            break;
            }
            else if(temp->val<p->val&&temp->val<q->val){ lca=temp; temp=temp->right;
            }
             else if(temp->val>p->val&&temp->val>q->val){ lca=temp;
             temp=temp->left;
             }
            else if(temp->val==p->val||temp->val==q->val) {lca=temp;break;
            }

        }
        return lca;

    }
};