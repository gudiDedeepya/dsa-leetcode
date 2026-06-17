class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int total = accumulate(cardPoints.begin(),
                               cardPoints.end(),0);

        if(k==n)
            return total;

        int window = n-k;

        int sum = 0;
        int l=0;
        int msum=INT_MAX;

       for(int i=0;i<n;i++){
        sum+=cardPoints[i];
        if(i-l+1==window){
            msum=min(msum,sum);
            sum-=cardPoints[l];
            l++;
        }

       }

        return total -msum;
    }
};