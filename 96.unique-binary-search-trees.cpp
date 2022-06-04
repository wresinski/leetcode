class Solution {
public:
    // 卡塔兰数
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
    /*
    // 动态规划
    int numTrees(int n) {
	vector<int> dp(n+1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i=2; i<=n; ++i) {
	    for (int j=0; j<i; ++j) {
	        dp[i] += dp[j]*dp[i-j-1];
	    }
	}
	return dp[n];
    }
    */
};
