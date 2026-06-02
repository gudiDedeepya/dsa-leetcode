class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        // Push all 0s into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   !vis[nr][nc]) {

                    vis[nr][nc] = 1;
                    dist[nr][nc] = dist[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};