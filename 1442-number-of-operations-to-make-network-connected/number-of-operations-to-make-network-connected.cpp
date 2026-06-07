
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt=0;
        int cntc=0;
        if(connections.size()<n-1) return -1;
        for(auto vec:connections){
            if(ds.findUPar(vec[0])==ds.findUPar(vec[1]))
             cnt++;
             else{
                ds.unionBySize(vec[0],vec[1]);
             }
        }
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cntc++;
        }
        if(cnt<cntc-1) return -1;
        return cntc-1;


    }
};