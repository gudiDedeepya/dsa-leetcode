class Solution {
public:
int cnt=0;
int paths(int row,int col,int m,int n,vector<vector<int>>&dp){
    if(row==m-1&&col==n-1){
       return 1;
    }
    if(dp[row][col]!=0) {
        return dp[row][col];
    }
    int right=0;
    int down=0;
    if(row<m-1){
        down=paths(row+1,col,m,n,dp);
    }
    if(col<n-1){
        right=paths(row,col+1,m,n,dp);
    }
    return dp[row][col]=down+right;

}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return paths(0,0,m,n,dp);
        
        
    }
};