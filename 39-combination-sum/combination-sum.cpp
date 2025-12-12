

class Solution {
    
public:
    void generate(const vector<int>& candidates, int target,
                  vector<vector<int>>& combo, int index,
                  vector<int>& ls, int sum) {
        if (sum == target) {
            combo.push_back(ls);
            return;
        }
        if (index == (int)candidates.size() || sum > target) return;
        ls.push_back(candidates[index]);
        generate(candidates, target, combo, index, ls, sum + candidates[index]);
        ls.pop_back();
        generate(candidates, target, combo, index + 1, ls, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combo;
        vector<int> ls;
        generate(candidates, target, combo, 0, ls, 0);
        return combo;
    }
};
