

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        for(auto vec:edges){
            if(ds.findUPar(vec[0])==ds.findUPar(vec[1]))
               return vec;
            else
                ds.unionBySize(vec[0],vec[1]);
        }
        vector<int>ans;
        return ans;
    }
};