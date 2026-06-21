class Solution {
public:
int paths(int row,int col,int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
    if(row==m-1&&col==n-1){
       if(obstacleGrid[row][col]!=1)
       return 1;
       return 0;
    }
    if(dp[row][col]!=0) {
        return dp[row][col];
    }
    int right=0;
    int down=0;
    if(row<m-1&&obstacleGrid[row+1][col]!=1){
        down=paths(row+1,col,m,n,obstacleGrid,dp);
    }
    if(col<n-1&&obstacleGrid[row][col+1]!=1){
        right=paths(row,col+1,m,n,obstacleGrid,dp);
    }
    return dp[row][col]=down+right;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
         vector<vector<int>>dp(m,vector<int>(n,0));
        return paths(0,0,m,n,obstacleGrid,dp);
        
    }
};