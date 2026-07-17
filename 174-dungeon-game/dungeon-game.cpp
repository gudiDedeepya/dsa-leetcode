class Solution {
public:
    int m,n;
    vector<vector<int>> dp;

    int dfs(int i,int j,vector<vector<int>>& dungeon){

        if(i>=m || j>=n)
            return INT_MAX;

        if(i==m-1 && j==n-1)
            return max(1,1-dungeon[i][j]);

        if(dp[i][j]!=-1)
            return dp[i][j];

        int right=dfs(i,j+1,dungeon);
        int down=dfs(i+1,j,dungeon);

        int need=min(right,down);

        return dp[i][j]=max(1,need-dungeon[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        m=dungeon.size();
        n=dungeon[0].size();

        dp.assign(m,vector<int>(n,-1));

        return dfs(0,0,dungeon);
    }
};