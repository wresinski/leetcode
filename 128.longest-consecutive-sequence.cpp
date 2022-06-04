class Solution {
public:
    // 哈希表
    int longestConsecutive(vector<int>& nums) {
	int n = nums.size();
	int res = 0;
	unordered_map<int,int> map;
	for (int i=0; i<n; ++i) {
	    map[nums[i]]++;
	}

	for (int i=0; i<n; ++i) {
	    if (map[nums[i]-1]==0) { // 当x-1不存在时才进行匹配
		int j = 1;
		while (map[nums[i]+j]) j++;
		res = max(res, j);
	    }
	}
	return res;
    }
    /*
    // 先排序
    int longestConsecutive(vector<int>& nums) {
	if (nums.size()==0) return 0;
	int res = 1;
	int count = 1;
	sort(nums.begin(), nums.end());
	for (int i=1; i<nums.size(); ++i) {
	    if (nums[i]==nums[i-1]+1) {
	        ++count;
		res = max(res, count);
	    }
	    else if (nums[i]>nums[i-1]+1) {
		count = 1;
	    }
	}
	return res;
    }
    */
};
