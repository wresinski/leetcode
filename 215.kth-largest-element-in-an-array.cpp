class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
	int length = nums.size();
	for (int i=0; i<k; ++i) {
	    heapSort(nums, length--);
	    swap(nums[0], nums[length]);
	}
	return nums[length];
    }
    void heapSort(vector<int>& nums, int length) {
	for (int i=length/2-1; i>=0; --i) {
	    adjust(nums, length, i);
	}
    }
    void adjust(vector<int>& nums, int length, int i) {
	int k = 2*i+1;
	while (k<length) {
	    if (k+1<length&&nums[k+1]>nums[k]) {
		k = k+1;
	    }
	    if (nums[k]>nums[i]) {
		swap(nums[k], nums[i]);
		i = k;
		k = 2*i+1;
	    }
	    else {
	        break;
	    }
	}
    }
};
