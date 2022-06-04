class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
	int m = text1.size();
	int n = text2.size();
	vector<int> dp(n+1); // 数组优化为一维
	int temp1;
	for (int i=1; i<=m; ++i) {
	    temp1 = 0;
	    for (int j=1; j<=n; ++j) {
		int temp2 = temp1;
		temp1 = text1[i-1]==text2[j-1]?(dp[j-1]+1):max(dp[j],temp1);
		dp[j-1] = temp2;
	    }
	    dp[n] = temp1;
	}
	return temp1;
    }
};
