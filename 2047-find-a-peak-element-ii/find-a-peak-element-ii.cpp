class Solution {
public:
int findmaxrow(vector<vector<int>>& mat,int n,int m,int col){
          int index=-1;
          int maxi=-1;
          for(int i=0;i<n;i++){
             if(mat[i][col]>maxi){
             maxi=mat[i][col];
             index=i;
             }
          }
          return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int mid,low=0,high=m-1;

        while(low<=high){
            mid=(low+high)/2;
           int maxrowind=findmaxrow(mat,n,m,mid);
           int left= mid-1 >=0 ?mat[maxrowind][mid-1]:-1;
           int right= mid+1 <m ?mat[maxrowind][mid+1]:-1;
           if(mat[maxrowind][mid]>left&&mat[maxrowind][mid]>right){
            return {maxrowind,mid};
           }
           else if(mat[maxrowind][mid]<left)
           high=mid-1;
           else 
           low=mid+1;

        }
        return {-1,-1};
    }
};