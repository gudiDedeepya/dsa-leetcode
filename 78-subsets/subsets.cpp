class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int i, vector<int>& nums, vector<int>& curr) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // OPTION 1: Include nums[i]
        curr.push_back(nums[i]);
        backtrack(i + 1, nums, curr);

        // remove and backtrack for next option
        curr.pop_back();

        // OPTION 2: Do NOT include nums[i]
        backtrack(i + 1, nums, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(0, nums, curr);
        return ans;
    }
};
