class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int distinct = st.size();

        unordered_map<int,int> mp;

        int n = nums.size();
        int l = 0;
        int ans = 0;

        for(int r = 0; r < n; r++) {

            mp[nums[r]]++;

            while(mp.size() == distinct) {

                ans += (n - r);

                mp[nums[l]]--;

                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                l++;
            }
        }

        return ans;
    }
};