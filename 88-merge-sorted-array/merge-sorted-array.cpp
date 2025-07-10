class Solution {
public:
    
    void swapIfGreater(int &a, int &b) {
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
            
                if (left < m && right < m) {
                    swapIfGreater(nums1[left], nums1[right]);
                }
            
                else if (left < m && right >= m) {
                    swapIfGreater(nums1[left], nums2[right - m]);
                }
            
                else {
                    swapIfGreater(nums2[left - m], nums2[right - m]);
                }

                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }

    
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};
