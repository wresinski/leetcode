class Solution {
public:
    // 单调栈优化
    int maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int res = 0;
	vector<vector<int>> left(m, vector<int>(n));
	for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j) {
		int pre = j>0?left[i][j-1]:0;
		left[i][j] = matrix[i][j]=='1'?pre+1:0;
	    }
	}

	vector<int> lr(m);
	vector<int> rl(m);
	for (int j=0; j<n; ++j) {
	    stack<int> s;
	    for(int i=0;i<m;++i) rl[i] = m;
	    for(int i=0;i<m;++i) {
		while(!s.empty()&&left[s.top()][j]>left[i][j]) {
		    rl[s.top()] = i;
		    s.pop();
		}
		if(!s.empty()) {
		    lr[i] = s.top();
		}
		else {
		    lr[i] = -1;
		}
		s.push(i);
	    }
	    for(int i=0;i<m;++i) {
		int temp = left[i][j]*(rl[i]-lr[i]-1);
		if(temp>res) res = temp;
	    }
	}
	return res;
    }
    /*
    // 暴力法
    int maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int res = 0;
	vector<vector<int>> left(m, vector<int>(n));
	for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j) {
		int pre = j>0?left[i][j-1]:0;
		left[i][j] = matrix[i][j]=='1'?pre+1:0;
	    }
	}

	for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j) {
		int width = INT_MAX;
		for (int k=i; k>=0; --k) {
		    if (left[k][j]==0) break;
		    width = min(width, left[k][j]);
		    res = max(res, width*(i-k+1));
		}
	    }
	}
	return res;
    }
    */
};
