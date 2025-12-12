

class Solution {
public:
void generate( vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ls,int target,int index){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(ls);
             
            }
               return;
        }
            if(candidates[index]<=target){
                ls.push_back(candidates[index]);
                 generate(candidates,ans,ls,target-candidates[index],index);
                 ls.pop_back();
            }
                  generate(candidates,ans,ls,target,index+1);
            
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
              vector<vector<int>>ans;
              vector<int>ls;
              generate(candidates,ans,ls,target,0);
              return ans;
    } 
};
