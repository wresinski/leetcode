class Solution {
public:
    int longestValidParentheses(string s) {
	int n = s.size();
	int res = 0;
	int left = 0;
	int i = 0;
	int j = i-1;
	while (j<n-1) { // 从左往右
	    ++j;
	    if (s[j]=='(') {
	        ++left;
	    }
	    else {
		--left;
	    }

	    if (left<0) {
	        i = j+1;
		left = 0;
	    }
	    else if (left==0&&j-i+1>res) {
	        res = j-i+1;
	    }
	}

	left = 0;
	i = n-1;
	j = i+1;
	while (j>0) { // 从右往左
	    --j;
	    if (s[j]=='(') {
	        ++left;
	    }
	    else {
		--left;
	    }

	    if (left>0) {
	        i = j-1;
		left = 0;
	    }
	    else if (left==0&&i-j+1>res) {
	        res = i-j+1;
	    }
	}
	return res;
    }
    /*
    // 栈
    int longestValidParentheses(string s) {
	int maxlen = 0;
	stack<int> st; 
	st.push(-1);
	for (int i=0; i<s.size(); ++i) {
	    if (s[i]=='(') {
	        st.push(i);
	    }
	    else {
		st.pop();
		if (st.empty()) {
		    st.push(i);
		}
		else {
		    maxlen = max(maxlen, i-st.top()); // 栈顶为左边最近一个未匹配括号的位置
		}
	    }
	}
	return maxlen;
    }
    */
    /*
    // 动态规划
    int longestValidParentheses(string s) {
	int n = s.size();
	int maxlen = 0;
	vector<int> dp(n);
	for (int i=1; i<n; ++i) {
	    if (s[i]==')'&&s[i-1]=='(') {
	        dp[i] = i-2>=0?dp[i-2]+2:2;
	    }
	    else if (s[i]==')'&&s[i-1]==')'&&i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(') {
		dp[i] = dp[i-1]+(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]+2:2);
	    }
	    if (maxlen<dp[i]) maxlen = dp[i];
	}
	return maxlen;
    }
    */
};
