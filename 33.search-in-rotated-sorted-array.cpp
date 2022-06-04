class Solution {
public:
    int search(vector<int>& nums, int target) {
	int low = 0;
	int high = nums.size()-1;
	while (low<=high) {
	    int mid = (low+high)/2;
	    if (nums[mid]==target) return mid;
	    if (nums[low]<=nums[mid]) {
		if (nums[low]<=target && nums[mid]>target) {
		    high = mid-1;
		}
		else {
		    low = mid+1;
		}
	    }
	    else {
		if (nums[high]>=target && nums[mid]<target) {
		    low = mid+1;
		}
		else {
		    high = mid-1;
		}
	    }
	}
	return -1;
    }
    /*
    // 先二分找出最小值，再在正确的区间内二分搜索target
    int search(vector<int>& nums, int target) {
	int low = 0;
	int high = nums.size()-1;
	while (low<high) {
	    int mid = (low+high)/2;
	    if(nums[mid]>nums[high]) low = mid+1;
	    else high = mid;
	}
	
	if (low!=0&&target>=nums[0]) {
	    high = low-1;
	    low = 0;
	}
	else {
	    high = nums.size()-1;
	}
	while (low<=high) {
	    int mid = (low+high)/2;
	    if(nums[mid]<target) low = mid+1;
	    else if(nums[mid]>target) high = mid-1;
	    else return mid;
	}
	return -1;
    }
    */
};
