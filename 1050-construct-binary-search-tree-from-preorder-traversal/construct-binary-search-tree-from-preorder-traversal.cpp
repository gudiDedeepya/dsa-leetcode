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
    TreeNode* construct(vector<int>& preorder,int prest,int prend,vector<int>& inorder,int inorst,int inend,unordered_map<int,int> &inor){
        if(prest>prend||inorst>inend) return NULL;
        TreeNode*node=new TreeNode(preorder[prest]);
        int inroot=inor[node->val];
        int numleft=inroot-inorst;
        node->left=construct(preorder,prest+1,prest+numleft,inorder,inorst,inroot-1,inor);
         node->right=construct(preorder,prest+1+numleft,prend,inorder,inroot+1,inend,inor);

    return node;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        //1,5,7,8,10,12
        int n=inorder.size();
        unordered_map<int,int>inor;
        for(int i=0;i<n;i++)
        inor[inorder[i]]=i;
        return construct(preorder,0,n-1,inorder,0,n-1,inor);

    }
};