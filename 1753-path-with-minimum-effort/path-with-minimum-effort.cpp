class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        int n=heights.size();
        int m=heights[0].size(); 
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
                int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
             for(int d = 0; d < 4; d++) {
             int nr = r + dr[d];
             int nc = c + dc[d];

             if(nr>=0&&nr<n&&nc>=0&&nc<m){
                int newEffort =max(diff,abs(heights[r][c] - heights[nr][nc]));

                if(newEffort < dist[nr][nc]){
                dist[nr][nc] = newEffort;
                 pq.push({newEffort,{nr,nc}});
             }
}


        }
        }
        return dist[n-1][m-1];
    }
};