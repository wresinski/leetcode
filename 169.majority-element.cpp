class Solution {
public:
    // Boyer-Moore投票算法
    int majorityElement(vector<int>& nums) {
	int count = 0;
	int res;
	for (int n : nums) {
	    if (count==0) {
	        res = n;
	    }
	    if (res==n) {
	        ++count;
	    }
	    else {
	        --count;
	    }
	}
	return res;
    }
    /*
    // 分治
    int majorityElement(vector<int>& nums) {
	return getMajorityElement(nums, 0, nums.size()-1);
    }
    int getMajorityElement(vector<int>& nums, int i, int j) {
	if (i==j) {
	    return nums[i];
	}
	int mid = (i+j)/2;
	int leftM = getMajorityElement(nums, i, mid);
	int rightM = getMajorityElement(nums, mid+1, j);
	int leftC = 0;
	int rightC = 0;
	for (int k=i; k<=j; ++k) {
	    if (nums[k]==leftM) ++leftC;
	    else if (nums[k]==rightM) ++rightC;
	}
	return leftC>rightC?leftM:rightM;
    }
    */
    /*
    // 随机法
    int majorityElement(vector<int>& nums) {
	while (1) {
	    int res = nums[rand()%nums.size()];
	    int count = 0;
	    for (int n : nums) {
		if (n==res) ++count;
	    }
	    if (count>nums.size()/2) {
		return res;
	    }
	}
	return -1;
    }
    */
    /*
    // 哈希表
    int majorityElement(vector<int>& nums) {
	unordered_map<int,int> map;
	int count = 0;
	int res = 0;
	for (int n : nums) {
	    ++map[n];
	    if (count<map[n]) {
		count = map[n];
		res = n;
	    }
	}
	return res;
    }
    */
    /*
    // 排序
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
    */
};
