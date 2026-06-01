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
int maxi=0;
    void zigzag(TreeNode* root,int state,int length){
        if(root==NULL) return;
        //root=0,left=1,right=2
        if(state==0){
            if(root->left){
            maxi=max(maxi,length+1);
            zigzag(root->left,1,length+1);
            }
            if(root->right){
            maxi=max(maxi,length+1);
            zigzag(root->right,2,length+1);
            }

        }
        else if(state==2){
            if(root->left){
                maxi=max(maxi,length+1);
                zigzag(root->left,1,length+1);
            }
                    zigzag(root->right,2,1);
                
        }
        
        else {
            if(root->right){
                maxi=max(maxi,length+1);
                zigzag(root->right,2,length+1);
                }
                
                    zigzag(root->left,1,1);
                
        }
    }
    int longestZigZag(TreeNode* root) {
        zigzag(root,0,0);
        return maxi;
    }
};