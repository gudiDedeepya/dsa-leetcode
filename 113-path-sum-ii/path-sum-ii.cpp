class Solution {
public:

    void paths(TreeNode* root,
               int targetSum,
               vector<vector<int>>& ans,
               vector<int>& path,
               long long sum) {

        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL) {

            if(sum == targetSum)
                ans.push_back(path);

            return;
        }

        if(root->left) {

            path.push_back(root->left->val);

            paths(root->left,
                  targetSum,
                  ans,
                  path,
                  sum + root->left->val);

            path.pop_back();
        }

        if(root->right) {

            path.push_back(root->right->val);

            paths(root->right,
                  targetSum,
                  ans,
                  path,
                  sum + root->right->val);

            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        vector<int> path;

        path.push_back(root->val);

        paths(root,
              targetSum,
              ans,
              path,
              root->val);

        return ans;
    }
};