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
void markParents(TreeNode* root,
                 unordered_map<TreeNode*, TreeNode*>& parents) {

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()) {

        TreeNode* current = q.front();
        q.pop();

        if(current->left) {

            parents[current->left] = current;
            q.push(current->left);
        }

        if(current->right) {

            parents[current->right] = current;
            q.push(current->right);
        }
    }
}
void dis(TreeNode*root,TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*>parents,vector<int>&ans){
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        unordered_map<TreeNode*, bool> visited;
        visited[target]=true;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(cnt == k){
    ans.push_back(node->val);
    continue;
}
            if(node->left&&!visited[node->left]){
                visited[node->left]=true;
                q.push({node->left,cnt+1});
            }

            if(node->right&&!visited[node->right]) {
                visited[node->right]=true;
                q.push({node->right, cnt+1});
            }
            if(parents[node]&&!visited[parents[node]]){
                visited[parents[node]]=true;
                 q.push({parents[node], cnt+1});
            }

 }



}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int cnt=0;
        vector<int>ans;
        if(root==NULL) return ans;
        if(k==0){
            ans.push_back(target->val);
            return ans;
        }
        unordered_map<TreeNode*, TreeNode*>parents;
        markParents(root,parents);
        dis(root,target,k,parents,ans);
        
       return ans;

    }
};