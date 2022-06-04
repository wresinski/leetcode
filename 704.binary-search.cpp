class Solution {
public:
    int search(vector<int>& nums, int target) {
	int low = 0;
	int high = nums.size() - 1;
	while (low<=high) {
	    int mid = (low+high)/2;
	    if(nums[mid]<target) {
		low = mid + 1;
	    }
	    else if(nums[mid]>target) {
		high = mid - 1;
	    }
	    else return mid;
	}
	return -1;
    }
    /*
    int search(vector<int>& nums, int target) {
        if(nums[0]==target) return 0;
        if(nums[nums.size()-1]==target) return nums.size()-1;
        return binarySearch(nums,0,nums.size(),target);
    }
    int binarySearch(vector<int>& nums,int i,int j,int target)
    {
        if(j-i==1) return -1;
        int k = (i+j)/2;
        if(nums[k]>target) return binarySearch(nums,i,k,target);
        if(nums[k]<target) return binarySearch(nums,k,j,target);
        return k;
    }
    */
};
