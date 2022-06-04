class Solution {
public:
    // 双指针
    void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int i;
	for (i=n-2; i>=0&&nums[i]>=nums[i+1]; --i);
	if (i>=0) {
	    int j;
	    for (j=n-1; j>i&&nums[j]<=nums[i]; --j);
	    swap(nums[i], nums[j]);
	}
	reverse(nums.begin()+i+1, nums.end());
    }
    /*
    void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int i;
	for (i=n-2; i>=0; --i) {
	    int temp = INT_MAX;
	    int temp_i = -1;
	    for (int j=i+1; j<n; ++j) {
		if (nums[j]>nums[i]&&nums[j]<temp) {
		    temp = nums[j];
		    temp_i = j;
		}
	    }
	    if (temp_i!=-1) {
		nums[temp_i] = nums[i];
		nums[i] = temp;
		break;
	    }
	}
	sort(nums.begin()+i+1, nums.end());
    }
    */
};
