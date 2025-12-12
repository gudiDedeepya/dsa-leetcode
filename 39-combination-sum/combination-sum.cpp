

class Solution {
    
public:
    void generate(const vector<int>& candidates, int target,
                  vector<vector<int>>& combo, int index,
                  vector<int>& ls, int sum) {
        // Found a valid combination
        if (sum == target) {
            combo.push_back(ls);
            return;
        }
        // Out of bounds or already exceeded target
        if (index == (int)candidates.size() || sum > target) return;

        // Option 1: include current candidate (we keep index to allow reuse)
        ls.push_back(candidates[index]);
        generate(candidates, target, combo, index, ls, sum + candidates[index]);
        ls.pop_back();

        // Option 2: exclude current candidate and move to next
        generate(candidates, target, combo, index + 1, ls, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combo;
        vector<int> ls;
        generate(candidates, target, combo, 0, ls, 0);
        return combo;
    }
};
