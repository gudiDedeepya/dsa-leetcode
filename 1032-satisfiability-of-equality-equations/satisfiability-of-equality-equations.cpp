


class DisjointSet {
public:
    vector<int> parent,rank;

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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for(auto vec:equations){
            if(vec[1]!='!'){
                ds.unionBySize(vec[0]-'a',vec[3]-'a');
            }
        }
        for(auto vec:equations){
            if(vec[1]=='!'){
                if(ds.findUPar(vec[0]-'a')==ds.findUPar(vec[3]-'a'))
                return false;
            }
        }
        return true;
    }
};