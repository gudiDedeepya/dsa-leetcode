class Solution {
public:

void bfs(vector<vector<char>>& grid,int i,int j,vector<int>&visited,int n,int m){
     queue<pair<int,int>>q;
     q.push({i,j});
      int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            for(int d=0;d<4;d++){
                 int nr = a + dr[d];
                    int nc = b + dc[d];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < m &&
                       grid[nr][nc] == '1'&&!visited[nr*m+nc]) {
                        q.push({nr,nc});
                        visited[nr*m+nc]=1;
                       }
            }
        }

                        
}
    int numIslands(vector<vector<char>>& grid) {
               int n=grid.size();
        int m=grid[0].size();  
        vector<int>visited(n*m+1,0);
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!visited[i*m+j]){
                    visited[i*m+j]=1;
                    island++;
                    bfs(grid,i,j,visited,n,m);
                }
            }
        }
        return island;
    }
};