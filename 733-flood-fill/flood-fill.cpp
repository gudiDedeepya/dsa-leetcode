class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int co1=image[sr][sc];
        if(co1==color) return image;
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
             for(int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < m &&
                       image[nr][nc] == co1) {

                        image[nr][nc] = color;

                        q.push({nr, nc});
                       }
             }
        }
        return image;

        }
    
};