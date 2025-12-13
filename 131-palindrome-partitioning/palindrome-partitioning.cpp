class Solution {
public:
bool ispalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--])
        return false;
    }
    return true;
}
void generate(string s,vector<vector<string>>&ans,vector<string>&ls,int ind){
    if(ind==s.size()){
    ans.push_back(ls);
    return;
}
for(int i=ind;i<s.size();i++){
    if(ispalindrome(s,ind,i)){
        ls.push_back(s.substr(ind,i-ind+1));
        generate(s,ans,ls,i+1);
        ls.pop_back();
    }
}
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ls;
        generate(s,ans,ls,0);
        return ans;
    }
};