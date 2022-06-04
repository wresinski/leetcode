class Solution {
public:
    // 双指针
    int trap(vector<int>& height) {
	int n = height.size();
	int res = 0;
	int i = 0;
	int j = n-1;
	int leftMax = 0, rightMax = 0;
	while (i<j) {
	    leftMax = max(leftMax, height[i]);
	    rightMax = max(rightMax, height[j]);
	    if (leftMax<rightMax) {  // 这里换成height[i]<height[j]是等价的
		res += leftMax-height[i++];
	    }
	    else {
		res += rightMax-height[j--];
	    }
	}
	return res;
    }
    /*
    // 单调栈
    int trap(vector<int>& height) {
	int n = height.size();
	int res = 0;
	stack<int> st;
	for (int i=0; i<n; ++i) {
	    while (!st.empty()&&height[i]>height[st.top()]) {
		int top = st.top();
		st.pop();
		if (st.empty()) break;
		res += (min(height[i], height[st.top()])-height[top])*(i-st.top()-1);
	    }
	    st.push(i);
	}
	return res;
    }
    */
    /*
    // 动态规划
    int trap(vector<int>& height) {
	int n = height.size();
	int res = 0;
	vector<int> leftMax(n);
	leftMax[0] = height[0];
	vector<int> rightMax(n);
	rightMax[n-1] = height[n-1];

	for (int i=1; i<n; ++i) {
	    leftMax[i] = max(leftMax[i-1], height[i]);
	}
	for (int i=n-2; i>=0; --i) {
	    rightMax[i] = max(rightMax[i+1], height[i]);
	}

	for (int i=0; i<n; ++i) {
	    res += min(leftMax[i], rightMax[i])-height[i];
	}

	return res;
    }
    */
    /*
    // 双向扫描
    int trap(vector<int>& height) {
	int n = height.size();
	int sum = 0;
	int i = 0;
	int j = i;
	int temp = 0;
	while (j<n) {  // 从左到右
	    if (height[j]<height[i]) {
		temp += height[i]-height[j];
	    }
	    else {
		i = j;
		sum += temp;
		temp = 0;
	    }
	    ++j;
	}

	i = n-1;
	j = i;
	temp = 0;
	while (j>=0) {  // 从右到左
	    if (height[j]<=height[i]) {
		temp += height[i]-height[j];
	    }
	    else {
		i = j;
		sum += temp;
		temp = 0;
	    }
	    --j;
	}
	return sum;
    }
    */
};
