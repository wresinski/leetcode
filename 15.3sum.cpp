class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	int n = nums.size();
	for (int i=0; i<n-2; ++i) {
	    if (i>0&&nums[i]==nums[i-1]) continue; // 不能和上次数字一样
	    int j = i+1;
	    int k = n-1;
	    int target = -nums[i];
	    while (j<k) {
		if (j>i+1&&nums[j]==nums[j-1]) { // 不能和上次数字一样
		    ++j;
		    continue;
		}
		int sum = nums[j]+nums[k];
	        if (sum<target) {
		    ++j;
		}
		else if (sum>target) {
		    --k;
		}
		else {
		    res.push_back({ nums[i], nums[j], nums[k] });
		    ++j; // 如果接下来还有满足条件的解，必然是一增一减
		    --k;
		}
	    }
	}
	return res;
    }
};
