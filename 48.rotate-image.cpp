class Solution {
public:
    // 用翻转代替选转
    void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int i=0; i<n/2; ++i) {
	    for (int j=0; j<n; ++j) {
		swap(matrix[i][j], matrix[n-i-1][j]);
	    }
	}
	for (int i=0; i<n-1; ++i) {
	    for (int j=i+1; j<n; ++j) {
	        swap(matrix[i][j], matrix[j][i]);
	    }
	}
    }
    /*
    // 临时变量
    void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int k=0; k<n/2; ++k) {
	    for (int i=k; i<n-k-1; ++i) {
		int x = k, y = i;
		for (int j=1; j<4; ++j) {
		    int temp = matrix[k][i];
		    int temp_x = y;
		    int temp_y = n-x-1; 
		    x = temp_x;
		    y = temp_y;
		    matrix[k][i] = matrix[x][y];
		    matrix[x][y] = temp;
		}
	    }
	}
    }
    */
};
