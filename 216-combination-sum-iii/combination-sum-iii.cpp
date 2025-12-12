class Solution {
public:
void generate(int start,int k,int n,vector<vector<int>>&ans,vector<int>ls){
    if(ls.size()==k){
        if(n==0){
    ans.push_back(ls);
    return;
        }
    }
    for(int i=start;i<10;i++){
        if(i>n)break;
        ls.push_back(i);
        generate(i+1,k,n-i,ans,ls);
        ls.pop_back();

}


}
    vector<vector<int>> combinationSum3(int k, int n) {
           vector<vector<int>>ans;
           vector<int>ls;                                      
          generate(1,k,n,ans,ls);
          return ans;
    }
};