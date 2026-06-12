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
      vector<TreeNode*> inorderTraversal(TreeNode* root) {
         vector<TreeNode*>inor;
         TreeNode*curr=root;
         stack<TreeNode*>st;
         if(root==NULL) return inor;
         while(curr!=NULL||!st.empty()){
         while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
         }
         curr=st.top();
         st.pop();
          inor.push_back(curr);
         curr=curr->right;
         }
         return inor;
    }


    void recoverTree(TreeNode* root) {
        vector<TreeNode*>inor=inorderTraversal(root);
        int n=inor.size();
        int cnt=0;
        int indx=-1;
        int indx2=-1;
      TreeNode* first = NULL;
TreeNode* second = NULL;

for(int i=0;i<n-1;i++){
    if(inor[i]->val > inor[i+1]->val){

        if(first == NULL)
            first = inor[i];

        second = inor[i+1];
    }
}  
        
       // if(cnt>2||indx==-1||indx2==-1) return false;
        swap(first->val,second->val);
    
    }
};