class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
	int n = nums.size();
	int low = 0;
	int high = n-1;
	int begin = -1;
	while (low<=high) {
	    int mid = (low+high)/2;
	    if (nums[mid]<target) {
	        low = mid+1;
	    }
	    else {
		high = mid-1;
	    }
	}
	if (low<n&&nums[low]==target) begin = low;
	else return {-1, -1};

	low = 0;
	high = n-1;
	int end = -1;
	while (low<=high) {
	    int mid = (low+high)/2;
	    if (nums[mid]<=target) {
	        low = mid+1;
	    }
	    else {
		high = mid-1;
	    }
	}
	if (high>=0&&nums[high]==target) end = high;
	return { begin, end };
    }
};
