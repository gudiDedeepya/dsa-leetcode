

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
bool strswap(string st1,string st2){
    if(st1.size()!=st2.size()) return false;
    int n=st1.size();
    int idx1=0;
    int idx2=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(st1[i]!=st2[i]){ cnt++;
        if(cnt==1) idx1=i;
        if(cnt==2) idx2=i;
        }
    }
    if(cnt==2){
        swap(st1[idx1],st1[idx2]);
        if(st1==st2) return true;
    }
    return false;
}
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DisjointSet ds(n);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(strs[i]==strs[j] || strswap(strs[i],strs[j])){
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        return cnt;
    }
};