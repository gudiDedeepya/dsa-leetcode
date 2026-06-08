class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
            int n=grid.size();
            DisjointSet ds(n*n);
            int max_len=-1;
                    int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                for(int d = 0; d < 4; d++) {
                  int nr = i + dr[d];
                   int nc = j+ dc[d];

             if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==1){
                        ds.unionBySize(i*n+j,nr*n+nc);
             }
                    }
                }
            }
            }
            for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){
            if(grid[i][j]==0) {
                    unordered_set<int>mpp;
                    int length=0;
                    for(int d = 0; d < 4; d++) {
                  int nr = i + dr[d];
                   int nc = j+ dc[d];

                   if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==1){
                        mpp.insert(ds.findUPar(nr*n+nc));
                   }
                    
                    }
                   for(auto it:mpp){
                     length+=ds.size[it];
                   }
                   max_len=max(length+1,max_len);

                }
            }
            }


    return max_len==-1?n*n:max_len;

    }
};