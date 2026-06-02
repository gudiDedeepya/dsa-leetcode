class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ones=0;
        queue<pair<int,int>>q;
        vector<int>visited(n*m+1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ones++;
                    if(i==0||i==m-1||j==0||j==n-1){
                        q.push({i,j});
                        visited[i*n+j]=1;
                    }
                }

            }
        }
        ones=ones-q.size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            for(int d=0;d<4;d++){
                 int nr = a + dr[d];
                    int nc = b + dc[d];

                    if(nr >= 0 && nr < m &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1&&!visited[nr*n+nc]) {
                        
                        ones--;
                        visited[nr*n+nc]=1;
                        q.push({nr,nc});
            }
        }
        }
        return ones;
    }
};