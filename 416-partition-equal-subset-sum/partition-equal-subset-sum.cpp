class Solution {
public:
   bool sum(int ind,int k,int n,vector<int>&nums,vector<vector<int>>&dp){
    if(k==0) return true;
    if(ind==n-1) return nums[ind]==k;
    if(dp[ind][k]!=-1) return dp[ind][k];
    bool notake=sum(ind+1,k,n,nums,dp);
    bool take=false;
    if(nums[ind]<=k) 
    take=sum(ind+1,k-nums[ind],n,nums,dp);

    return dp[ind][k]=take|notake;
    
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sumi=accumulate(nums.begin(),nums.end(),0);
        if(sumi%2) return false;
        int k=sumi/2;
        
  vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
  return sum(0,k,n,nums,dp);
    }
};