class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
	int a = 0;
	int b = 0;
	int x = 0;
	for(int i=0;i<nums.size();++i) {
	    x ^= nums[i];
	}
	x = (x==INT_MIN)?x:x&-x; //仅当x=INT_MIN时会溢出，且此时最低不为0的位为符号位，无需变换
	for(int i=0;i<nums.size();++i) {
	    if(nums[i]&x) a ^= nums[i];
	    else b ^= nums[i];
	}
	return vector<int>{a,b};
    }
};
