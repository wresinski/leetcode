class Solution {
public:
    // 贪心+二分查找
    int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	int len = 1;
	vector<int> d(n+1, nums[0]);
	for (int i=1; i<n; ++i) {
	    if (nums[i]>d[len]) {
	        len++;
		d[len] = nums[i];
	    }
	    else {
		int low = 1;
		int high = len-1;
		while (low<=high) {
		    int mid = (low+high)/2;
		    if (d[mid]<nums[i]) low = mid+1;
		    else high = mid-1;
		}
		d[low] = nums[i]; // 从之前的查找可知，d[high]之后到d[len]之前的都比nums[i]大
	    }
	}
	return len;
    }
    /*
    // 动态规划
    int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> f(n, 1);
	int res = 1;
	for (int i=1; i<n; ++i) {
	    for (int j=i-1; j>=0; --j) {
	        if (nums[i]>nums[j]) {
		    f[i] = max(f[i], f[j]+1);
		}
	    }
	    res = max(res, f[i]); 
	}
	return res;
    }
    */
};
