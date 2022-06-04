class Solution {
public:
    int numSquares(int n) {
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i=2; i<=n; ++i) {
	    int min_dp = INT_MAX;
	    for (int j=1; j*j<=i; ++j) {
		min_dp = min(min_dp, dp[i-j*j]);
	    }
	    dp[i] = 1+min_dp;
	}
	return dp[n];
    }
};
