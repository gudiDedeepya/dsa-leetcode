class Solution {
public:

bool bfs(vector<vector<int>>& grid,int mid){
        int t=mid;
        vector<int>dr={-1,1,0,0};
        int n=grid.size();
        vector<int>dc={0,0,-1,1};
        queue<pair<int,int>>q;
        if(grid[0][0]<=t){
        q.push({0,0});
        }
        //else return false;
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0]=1;

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(r==n-1&&c==n-1) return true;
            for(int d=0;d<4;d++){
                int nr=r+dr[d];
                int nc=c+dc[d];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]<=t&&!visited[nr][nc]){
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            }

        }
        return false;

}
    int swimInWater(vector<vector<int>>& grid) {
        int maxi=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[i][j]);
            }
        }
        int low=0;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(bfs(grid,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};