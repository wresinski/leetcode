class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int,int> map;
	for (int i=0; i<nums.size(); ++i) {
	    if (map.find(target-nums[i])!=map.end()) { // 这里不能写成map[target-nums[i]=0，因为元素位置本身就有可能是0
		return { i, map[target-nums[i]] };
	    }
	    map[nums[i]] = i;
	}
	return { };
    }
};
