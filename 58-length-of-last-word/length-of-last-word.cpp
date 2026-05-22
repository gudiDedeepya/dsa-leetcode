class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;

        // skip ending spaces
        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        int cnt = 0;

        // count last word length
        while(i >= 0 && s[i] != ' ') {
            cnt++;
            i--;
        }

        return cnt;
    }
};