class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0]=0;
       // vector<vector<int>> vis(n, vector<int>(n, 0));
        int dr[] = {-1,-1,-1,0,0,1,1,1};
int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();

            for(int d = 0; d < 8; d++) {
             int nr = a + dr[d];
             int nc = b + dc[d];

             if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==0&&dist[a][b]+1<dist[nr][nc]&&grid[nr][nc]==0){
                dist[nr][nc]=dist[a][b]+1;
                q.push({nr,nc});
             }
}



        }

        if(dist[n-1][n-1]!=1e9) return dist[n-1][n-1]+1;
        return -1;
    }
};