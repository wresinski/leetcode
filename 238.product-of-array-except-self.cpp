class Solution {
public:
    // O(1)空间复杂度
    vector<int> productExceptSelf(vector<int>& nums) {
	int length = nums.size();
	vector<int> res(length);
	for (int i=0; i<length; ++i) {
	    res[i] = i==0?1:nums[i-1]*res[i-1];
	}
	int r = 1;
	for (int i=length-2; i>=0; --i) {
	    r *= nums[i+1];
	    res[i] *= r;
	}
	return res;
    }
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
	int length = nums.size();
	vector<int> l(length), r(length), res(length);
	for (int i=0; i<length; ++i) {
	    l[i] = i==0?1:nums[i-1]*l[i-1];
	}
	for (int i=length-1; i>=0; --i) {
	    r[i] = (i==length-1)?1:nums[i+1]*r[i+1];
	}
	for (int i=0; i<length; ++i) {
	    res[i] = l[i]*r[i];
	}
	return res;
    }
    */
};
