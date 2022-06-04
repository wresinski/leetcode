class Solution {
public:
    int findDuplicate(vector<int>& nums) {
	int n = nums.size();
	int ans = 0;
	int bit_max = 21;
	while (!((n-1)>>bit_max)) {
	    --bit_max;
	}
	for (int bit = 0; bit <= bit_max; ++bit) {
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] & (1 << bit)) {
                    x += 1;
                }
                if (i >= 1 && (i & (1 << bit))) {
                    y += 1;
                }
            }
            if (x > y) {
                ans |= 1 << bit;
            }
	}
	return ans;
    }
};
