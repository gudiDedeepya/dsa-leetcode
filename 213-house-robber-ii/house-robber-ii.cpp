class Solution {
public:

   int robby(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>n) return 0;

        if(dp[i]!=-1) return dp[i];
         int take=robby(i+2,n,nums,dp)+nums[i];
         int nottake=robby(i+1,n,nums,dp);
        return dp[i]=max(take,nottake);
   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[n-1];
        vector<int>dp(nums.size()+1,-1);
        vector<int>dp1(nums.size()+1,-1);
       return max(robby(0,n-2,nums,dp),robby(1,n-1,nums,dp1));
    }
};