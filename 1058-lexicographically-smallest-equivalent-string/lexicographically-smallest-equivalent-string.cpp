
class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) {
        //rank.resize(n,0);
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
        if(pu>pv){
            parent[pu]=pv;
        }
        else if(pu<pv)
        parent[pv]=pu;
    }
};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        int n=s1.size();
        for(int i=0;i<n;i++){
            ds.unionBySize(s1[i]-'a',s2[i]-'a');
        }
        string output="";
    for(int i=0;i<baseStr.size();i++){
        output.push_back(ds.findUPar(baseStr[i]-'a')+'a');
    }
    return output;
    }
};