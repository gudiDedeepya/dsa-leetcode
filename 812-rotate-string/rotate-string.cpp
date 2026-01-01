class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string doubled=s+s;
        if(doubled.find(goal)!=-1)
        return true;
        return false;
    }
};