class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iRes = m+n-1;
        m--;n--;
        while(m>=0||n>=0)
        {
            if(m<0)
            {
                nums1[iRes] = nums2[n];
                n--;
            }
            else if(n<0)
            {
                nums1[iRes] = nums1[m];
                m--;
            }
            else
            {
                if(nums1[m]>nums2[n])
                {
                    nums1[iRes] = nums1[m];
                    m--;
                }
                else
                {
                    nums1[iRes] = nums2[n];
                    n--;
                }
            }
            iRes--;
        }
    }
};
