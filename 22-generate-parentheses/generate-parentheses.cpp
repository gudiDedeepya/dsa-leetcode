class Solution {
public:
    vector<string> result;

    void backtrack(int open, int close, int n, string curr) {
        if (open == n && close == n) {
            result.push_back(curr);
            return;
        }

        if (open < n)
            backtrack(open + 1, close, n, curr + "(");

        if (close < open)
            backtrack(open, close + 1, n, curr + ")");
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n, "");
        return result;
    }
};
