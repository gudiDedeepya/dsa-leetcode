class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char,int>mp1;
    for(char c:s)
    mp1[c]++;
vector<pair<char,int>>v(mp1.begin(),mp1.end());

sort(v.begin(),v.end(),[](auto &a,auto &b){
   return  a.second>b.second;
});

string ans="";
for(auto &p:v){
    ans+=string(p.second,p.first);
}
return ans;
    }
};