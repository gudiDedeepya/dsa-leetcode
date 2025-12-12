class Solution {
public:
void backtrack(vector<int>&nums,vector<vector<int>>&ans,vector<int>ls,int n,int ind){
        ans.push_back(ls);
    for(int i=ind;i<n;i++){
        if(i>ind&&nums[i]==nums[i-1])continue;
        ls.push_back(nums[i]);
        backtrack(nums,ans,ls,n,i+1);
        ls.pop_back();

    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ls;
        backtrack(nums,ans,ls,n,0);
        return ans;
    }
};