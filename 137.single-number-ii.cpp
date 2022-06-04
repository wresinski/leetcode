class Solution {
public:
    int singleNumber(vector<int>& nums) {
	int n = 0;
	int res = 0;
	while (n < 32) {
	    int sum = 0;
	    for (int i = 0; i < nums.size(); ++i) {
		sum += ((nums[i] >> n) & 1);
            }
	    res |= sum%3<<n;
	    n++;
        }
        return res;
    }
};
