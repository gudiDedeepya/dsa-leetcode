

class Solution {
    public:
    void generate(vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&ls,int ind){
        int n=candidates.size();
         if(target==0){
                ans.push_back(ls);
            }

        for(int i=ind;i<n;i++){
            if(candidates[i]>target) break;
            if(i>ind&&candidates[i]==candidates[i-1])
            continue;
          
            ls.push_back(candidates[i]);
            generate(candidates,target-candidates[i],ans,ls,i+1);
            ls.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<vector<int>>ans;
         vector<int>ls;
         generate(candidates,target,ans,ls,0);
         return ans;

    }
};
