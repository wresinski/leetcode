class Solution {
public:
  /*      left_part          |         right_part
   *A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
   *B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
   */
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if (m>n) return findMedianSortedArrays(nums2, nums1);
	int low = 0;
	int high = m; // 为什么是m？因为要做到两种情况，元素全在左边或元素全在右边
	while (low<=high) {
	    int i = (low+high)/2;
	    int j = (m+n+1)/2-i;
	    if (i==0||j==n||nums1[i-1]<=nums2[j]) {
	        low = i+1;
	    }
	    else {
		high = i-1;
	    }
	}
	int i = high;
	int j = (m+n+1)/2-i;
	if ((m+n)%2) {
	    return max(i==0?INT_MIN:nums1[i-1], j==0?INT_MIN:nums2[j-1]);
	}
	else {
	    return (max(i==0?INT_MIN:nums1[i-1], j==0?INT_MIN:nums2[j-1])+min(i==m?INT_MAX:nums1[i], j==n?INT_MAX:nums2[j]))/2.0;
	}
    }
    /*
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if ((m+n)%2) {
	    return getK(nums1, nums2, (m+n+1)/2);
	}
	else {
	    return (getK(nums1, nums2, (m+n)/2)+getK(nums1, nums2, (m+n)/2+1))/2.0;
	}
    }
    int getK(vector<int>& nums1, vector<int>& nums2, int k) {
	int m = 0;
	int n = 0;
	while (k>1&&m<nums1.size()&&n<nums2.size()) {
	    int k1 = k/2-1+m<nums1.size()?k/2-1:nums1.size()-1-m;
	    int k2 = k/2-1+n<nums2.size()?k/2-1:nums2.size()-1-n;
	    if (nums1[k1+m]<=nums2[k2+n]) {
	        m = k1+m+1;
		k = k-k1-1;
	    }
	    else {
		n = k2+n+1;
		k = k-k2-1;
	    }
	}
	if (m>=nums1.size()) {
	    return nums2[n+k-1];
	}
	else if (n>=nums2.size()) {
	    return nums1[m+k-1];
	}
	else {
	    return min(nums1[m], nums2[n]);
	}
    }
    */
};
