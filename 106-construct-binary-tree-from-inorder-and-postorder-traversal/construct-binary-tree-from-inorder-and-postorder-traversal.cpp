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
    TreeNode* buildtree(vector<int>& postorder,int prest,int preed,vector<int>& inorder,int inst,int ined,map<int,int>&mpp){
    if(prest>preed||inst>ined) return NULL;

    TreeNode* root=new TreeNode(postorder[preed]);
    int inroot=mpp[root->val];
    int numleft=inroot-inst;

    root->left=buildtree(postorder,prest,prest+numleft-1,inorder,inst,inroot-1,mpp);
    root->right=buildtree(postorder,prest+numleft,preed-1,inorder,inroot+1,ined,mpp);

    return root;                                                     






    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          map<int,int>mpp;
         for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
         }
        TreeNode* root=buildtree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};