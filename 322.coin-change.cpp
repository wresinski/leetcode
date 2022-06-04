class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount+1,amount+1);
	dp[0] = 0;
	for (int i=1; i<=amount; ++i) {
	    for (int j=0; j<coins.size(); ++j) {
	        int temp = i-coins[j];
		if (temp>=0) {
		    dp[i] = min(dp[i], dp[temp]+1);
		}
	    }
	}
	return dp[amount]>amount?-1:dp[amount];
    }
};