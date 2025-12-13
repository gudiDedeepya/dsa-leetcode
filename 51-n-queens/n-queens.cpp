class Solution {
public:
   void solve(int col,vector<int>&upperdiagonal,vector<int>&lowerdiagonal,vector<int>&leftrow,vector<vector<string>>&ans,vector<string>&board,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(upperdiagonal[n-1+col-row]==0&&leftrow[row]==0&&lowerdiagonal[row+col]==0){
            board[row][col]='Q';
            upperdiagonal[n-1+col-row]=1;
            leftrow[row]=1;
            lowerdiagonal[row+col]=1;
             solve(col+1,upperdiagonal,lowerdiagonal,leftrow,ans,board,n);
              board[row][col]='.';
            upperdiagonal[n-1+col-row]=0;
            leftrow[row]=0;
            lowerdiagonal[row+col]=0;
            

        }
    }
   }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        vector<vector<string>>ans;
        vector<int>upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0),leftrow(n,0);
        solve(0,upperdiagonal,lowerdiagonal,leftrow,ans,board,n);
        return ans;

    }
};