#include <setjmp.h>
class Solution {
public:
    /*
    // 双指针1
    void sortColors(vector<int>& nums) {
	int n = nums.size();
	int i = 0;
	int j = 0;
	int k = j;
	while (k<n) {
	    if (nums[k]==0) {
	        swap(nums[i], nums[k]);
		if (i<j) {
		    swap(nums[j], nums[k]);
		}
		++i;
		++j;
	    }
	    else if (nums[k]==1) {
	        swap(nums[j], nums[k]);
		++j;
	    }
	    ++k;
	}
    }
    */
    // 双指针2
    void sortColors(vector<int>& nums) {
	int n = nums.size();
	int i = 0;
	int j = n-1;
	int k = i;
	while (k>=i&&k<=j) {
	    if (nums[k]==0) {
	        swap(nums[i], nums[k]);
		++i;
		++k;
	    }
	    else if (nums[k]==2) {
	        swap(nums[j], nums[k]);
		--j;
		if (nums[k]==1) ++k;
	    }
	    else {
	        ++k;
	    }
	}
    }
    /*
    // 单指针交换
    void sortColors(vector<int>& nums) {
	int n = nums.size();
	int i = 0;
	int j = i;
	while (j<n) {
	    if (nums[j]==0) {
	        swap(nums[i], nums[j]);
		++i;
	    }
	    ++j;
	}

	j = i;
	while (j<n) {
	    if (nums[j]==1) {
	        swap(nums[i], nums[j]);
		++i;
	    }
	    ++j;
	}
    }
    */
    /*
    // 个数统计
    void sortColors(vector<int>& nums) {
	int count[3] = { 0 };
	int n = nums.size();
	for (int& i : nums) {
	    count[i]++;
	}

	int j = 0;
	for (int i=0; i<count[0]; ++i) {
	    nums[j++] = 0;
	}
	for (int i=0; i<count[1]; ++i) {
	    nums[j++] = 1;
	}
	for (int i=0; i<count[2]; ++i) {
	    nums[j++] = 2;
	}
    }
    */
};
