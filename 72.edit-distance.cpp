class Solution {
public:
    int minDistance(string word1, string word2) {
	int m = word1.size();
	int n = word2.size();
	vector<int> dp(n+1);
	for (int i=1; i<=n; ++i) dp[i] = i;
	int temp1;
	for (int i=1; i<=m; ++i) {
	    temp1 = i;
	    for (int j=1; j<=n; ++j) {
		int temp2 = temp1;
		if (word1[i-1]==word2[j-1]) { // d[i-1][j]-1<=d[i][j]<=d[i-1][j]恒成立，则dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]-1)＝dp[i-1][j-1]，dp[i][j-1]>=dp[i-1][j-1]-1，dp[i-1][j]>=dp[i-1][j-1]-1恒成立
		    temp1 = dp[j-1]-1;
		}
		else {
		    temp1 = min(dp[j], temp1);
		    temp1 = min(temp1, dp[j-1]);
		}
		temp1++;
		dp[j-1] = temp2;
	    }
	    dp[n] = temp1;
	}
	return dp[n];
    }
    /*
    int minDistance(string word1, string word2) {
	int m = word1.size();
	int n = word2.size();
	vector<int> dp(n+1);
	for (int i=1; i<=n; ++i) dp[i] = i;
	int temp1;
	for (int i=1; i<=m; ++i) {
	    temp1 = i;
	    for (int j=1; j<=n; ++j) {
		int temp2 = temp1;
		if (word1[i-1]==word2[j-1]) { // d[i-1][j]-1<=d[i][j]<=d[i-1][j]恒成立，则dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]-1)＝dp[i-1][j-1]，dp[i][j-1]>=dp[i-1][j-1]-1，dp[i-1][j]>=dp[i-1][j-1]-1恒成立
		    temp1 = dp[j-1]-1;
		}
		else {
		    temp1 = min(dp[j], temp1);
		    temp1 = min(temp1, dp[j-1]);
		}
		temp1++;
		dp[j-1] = temp2;
	    }
	    dp[n] = temp1;
	}
	return dp[n];
    }
    */
};
