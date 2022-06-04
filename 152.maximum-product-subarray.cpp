class Solution {
public:
    // 优化空间
    int maxProduct(vector<int>& nums) {
	int n = nums.size();
	int dpmax = nums[0], dpmin = nums[0];
	int res = nums[0];
	for (int i=1; i<n; ++i) {
	    if (nums[i]>0) {
	        dpmax = max(dpmax*nums[i], nums[i]);
		dpmin = min(dpmin*nums[i], nums[i]);
	    }
	    else {
		int temp = dpmax;
	        dpmax = max(dpmin*nums[i], nums[i]);
		dpmin = min(temp*nums[i], nums[i]);
	    }
	    res = max(res, dpmax);
	}
	return res;
    }
    /*
    // 动态规划
    int maxProduct(vector<int>& nums) {
	int n = nums.size();
	vector<int> dpmax(n), dpmin(n);
	dpmax[0] = nums[0];
	dpmin[0] = nums[0];
	int res = nums[0];
	for (int i=1; i<n; ++i) {
	    if (nums[i]>0) {
	        dpmax[i] = max(dpmax[i-1]*nums[i], nums[i]);
		dpmin[i] = min(dpmin[i-1]*nums[i], nums[i]);
	    }
	    else {
	        dpmax[i] = max(dpmin[i-1]*nums[i], nums[i]);
		dpmin[i] = min(dpmax[i-1]*nums[i], nums[i]);
	    }
	    res = max(res, dpmax[i]);
	}
	return res;
    }
    */
};
