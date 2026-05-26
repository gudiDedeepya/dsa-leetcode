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
TreeNode* buildtree(vector<int>& preorder,int prest,int preed,vector<int>& inorder,int inst,int ined,map<int,int>&mpp){
    if(prest>preed||inst>ined) return NULL;

    TreeNode* root=new TreeNode(preorder[prest]);
    int inroot=mpp[root->val];
    int numleft=inroot-inst;

    root->left=buildtree(preorder,prest+1,prest+numleft,inorder,inst,inroot-1,mpp);
    root->right=buildtree(preorder,prest+numleft+1,preed,inorder,inroot+1,ined,mpp);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
         for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
         }
        TreeNode* root=buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
        
    }
};