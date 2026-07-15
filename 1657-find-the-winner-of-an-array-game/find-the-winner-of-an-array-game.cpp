class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size()){
            return *max_element(arr.begin(),arr.end());
        }

        int maxi=*max_element(arr.begin(),arr.end());;

        vector<int>count(maxi+1,0);
        int winner=arr[0];

        for(int i=1;i<arr.size();i++){
            if(winner<arr[i]){
                count[winner]=0;
                winner=arr[i];
            }
            count[winner]++;
            if(count[winner]>=k)
                return winner;

        }
        return winner;
    }
};