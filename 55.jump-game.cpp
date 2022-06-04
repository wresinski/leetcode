class Solution {
public:
    // 贪心
    bool canJump(vector<int>& nums) {
	int n = nums.size();
	int m = 0;
	for (int i=0; i<n; ++i) {
	    if(i<=m) {
		if (nums[i]+i>m) {
		    m = nums[i]+i;
		}
	    }
	    else return false;
	}
	return true;
    }
    /*
    // 动态规划
    bool canJump(vector<int>& nums) {
	int n = nums.size();
	vector<int> b(n);
	b[0] = 1;
	for (int i=1; i<n; ++i) {
	    int j=i-1;
	    while (!(b[j]&&nums[j]+j>=i)) {
		if(j==0) return false;
		j--;
	    }
	    b[i] = 1;
	}
	return true;
    }
    */
};
