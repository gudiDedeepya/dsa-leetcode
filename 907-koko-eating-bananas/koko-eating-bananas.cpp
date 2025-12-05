class Solution {
public:
    int findmax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int x : piles) maxi = max(maxi, x);
        return maxi;
    }

    long long findtime(vector<int>& piles, int k){
        long long reqtime = 0;
        for(int x : piles){
            reqtime += (long long)(x + k - 1) / k;  // integer ceil
        }
        return reqtime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findmax(piles);
        int minspeed = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long totalH = findtime(piles, mid);

            if(totalH <= h){
                minspeed = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minspeed;
    }
};
