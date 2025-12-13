class Solution {
public:
   bool backtrack(vector<vector<char>>&board,int i,int j,string word,int ind){
    if(ind==word.size()){
    return true;
   }
   if(i>=board.size()||j>=board[0].size()||board[i][j]!=word[ind]){
    return false;
   }
   char temp=board[i][j];
   board[i][j]='#';
   bool found=backtrack(board,i+1,j,word,ind+1)||backtrack(board,i-1,j,word,ind+1)||backtrack(board,i,j+1,word,ind+1)||backtrack(board,i,j-1,word,ind+1);
   board[i][j]=temp;
   return found;
}

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(backtrack(board,i,j,word,0))
                return true;
            }
        }
        return false;
    }
};