class Solution {
public:
int findDays(vector<int>& weights, int mid){
    int load=0;
    int cap=mid;
    int days=1;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>cap){
            days++;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int numdays=findDays(weights,mid);
            if(numdays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};