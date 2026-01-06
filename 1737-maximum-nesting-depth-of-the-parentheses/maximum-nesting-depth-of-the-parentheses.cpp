class Solution {
public:
    int maxDepth(string s) {
        int curr_depth=0;
        int max_depth=0;
        for(char ch:s){
            if(ch=='('){
            curr_depth++;
            max_depth=max(curr_depth,max_depth);
            }
            else if(ch==')')
            curr_depth--;

        }
        return max_depth;
    }
};