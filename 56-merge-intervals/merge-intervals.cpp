class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>newin;
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();

        for(int i=0;i<n;i++){
            if(newin.empty()|| newin.back()[1]<intervals[i][0]) 
            newin.push_back(intervals[i]);

            else{
                newin.back()[1]=max(newin.back()[1],intervals[i][1]);
            }
        }
        return newin;
        
    }
};