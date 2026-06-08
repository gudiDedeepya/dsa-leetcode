class Solution {
public:

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
         priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int t=grid[0][0];
               int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

        while(!pq.empty()){
            auto it=pq.top();
            int time=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();
            if(r==n-1&&c==n-1) return time;
            t++;
            for(int d=0;d<4;d++){
                int nr = r + dr[d];
               int nc = c + dc[d];

                if(nr>=0&&nr<n&&nc>=0&&nc<n&&vis[nr][nc]!=1){
                    vis[nr][nc]=1;
                    if(grid[nr][nc]<=time)
                    pq.push({time,{nr,nc}});
                    else
                    pq.push({grid[nr][nc],{nr,nc}});
            }
        }

        }
        return -1;

    }
};