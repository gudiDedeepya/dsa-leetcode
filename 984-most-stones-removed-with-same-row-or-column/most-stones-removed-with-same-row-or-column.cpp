

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++)
        parent[i]=i;

    }

    int findUPar(int node) {
        if(node==parent[node]) return node;

        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv])
        parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n=stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                ds.unionBySize(i,j);
                }
            }
        }
                unordered_set<int>mpp;
        for(int i=0;i<n;i++){
           mpp.insert(ds.findUPar(i)); 
        }
        return stones.size()-mpp.size();
    }
};