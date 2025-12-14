class Solution {
public:
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

void solve(string digits,int ind,vector<string>&ans,string &ls){
           if(ind==digits.size()){
            ans.push_back(ls);
            return;
           }
           string letters=mp[digits[ind]-'0'];
           for(char ch:letters){
            ls.push_back(ch);
           solve(digits,ind+1,ans,ls);
           ls.pop_back();
         }
}
    vector<string> letterCombinations(string digits) {
         string ls;
         vector<string> ans;
         solve(digits,0,ans,ls);
         return ans;
    }
};