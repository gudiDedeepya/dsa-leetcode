class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
       // vector<int>visited(n*m+1);

          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    if(i==0||i==m-1||j==0||j==n-1){
                        q.push({i,j});
                        board[i][j]='S';
                    }
                }

            }
        }

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
                       board[nr][nc] == 'O') {

                        q.push({nr,nc});
                        board[nr][nc]='S';
                       }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]== 'S') board[i][j]='O';
            }
        }
    }

};