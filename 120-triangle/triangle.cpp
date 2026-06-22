class Solution {
public:
 int paths(vector<vector<int>>&triangle,int m,int i,int j,vector<vector<int>>&dp){
            if(i==m-1){
               return triangle[i][j]; 
            }

            if(dp[i][j]!=1e9) return dp[i][j];
            int west=INT_MAX;
            int down=INT_MAX;
        
             west=paths(triangle,m,i+1,j+1,dp)+triangle[i][j];
            
             down =paths(triangle,m,i+1,j,dp)+triangle[i][j];
            
            

       return dp[i][j]=min(west,down);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
          int m=triangle.size();
       // int n=grid[m-1].size();
       // vector<vector<int>>dp(triangle.begin(),triangle.end()));
       vector<vector<int>> dp(triangle.size());

         for(int i=0; i<triangle.size(); i++){
            dp[i] = vector<int>(triangle[i].size(), 1e9);
}

        return paths(triangle,m,0,0,dp);
    }
};