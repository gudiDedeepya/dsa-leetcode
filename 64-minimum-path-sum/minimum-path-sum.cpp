class Solution {
public:
    int min_sum=INT_MAX;
    int paths(vector<vector<int>>&grid,int m,int n,int i,int j,vector<vector<int>>&dp){
            if(i==m-1&&j==n-1){
               return grid[i][j]; 
            }
            if(dp[i][j]!=-1) return dp[i][j];
            int right=INT_MAX;
            int down=INT_MAX;
            if(i<m-1){
             right=paths(grid,m,n,i+1,j,dp)+grid[i][j];
            }
            if(j<n-1){
            down =paths(grid,m,n,i,j+1,dp)+grid[i][j];
            }

       return dp[i][j]=min(right,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return paths(grid,m,n,0,0,dp);
    }
};