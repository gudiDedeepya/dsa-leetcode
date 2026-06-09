class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
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
    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

        DisjointSet ds(maxNum + 1);

        for(int num : nums) {
            for(int factor = 2; factor * factor <= num; factor++) {
                if(num % factor == 0) {

                    ds.unionBySize(num, factor);
                    ds.unionBySize(num, num / factor);
                }
            }
        }

        unordered_map<int,int> cnt;
        int ans = 0;

        for(int num : nums) {
            int parent = ds.findUPar(num);
            cnt[parent]++;
            ans = max(ans, cnt[parent]);
        }

        return ans;
    }
};