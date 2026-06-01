class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        queue<int>q;

       int prov=0;
        for(int i=0;i<n;i++){
        if(!visited[i]){
         q.push(i);
         visited[i]=1;
        while(!q.empty()){
            int m=q.front();
            q.pop();
            for(int j=0;j<n;j++){
            if(!visited[j]&&isConnected[m][j]==1){
            visited[j]=1;
            q.push(j);
            }
            }
        }
        prov++;
        }
        }
    return prov;

    }
};