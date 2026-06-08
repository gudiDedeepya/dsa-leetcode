
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>mpp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end())
                  mpp[accounts[i][j]]=i;
                  else
                  ds.unionBySize(i,mpp[accounts[i][j]]);
            }
        }
        vector<string>output[n];
        for(auto email:mpp){
            string em=email.first;
            int node=ds.findUPar(email.second);
            output[node].push_back(em);

        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(output[i].size()==0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(output[i].begin(),output[i].end());

            for(auto st:output[i]){
                temp.push_back(st);
            }
            ans.push_back(temp);
        }
        return ans;
    }

};