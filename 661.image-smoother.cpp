class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
	int m = M.size();
	int n = M[0].size();
	vector<vector<int>> ret;
	for(int i=0;i<m;++i) {
	    ret.push_back(vector<int>());
	    for(int j=0;j<n;++j) {
		int count = 1;
		int sum = M[i][j];
		if(i>0) {
		    count++;
		    sum += M[i-1][j];
		}
		if(i>0&&j>0) {
		    count++;
		    sum += M[i-1][j-1];
		}
		if(j>0) {
		    count++;
		    sum += M[i][j-1];
		}
		if(i<m-1&&j>0) {
		    count++;
		    sum += M[i+1][j-1];
		}
		if(i<m-1) {
		    count++;
		    sum += M[i+1][j];
		}
		if(i<m-1&&j<n-1) {
		    count++;
		    sum += M[i+1][j+1];
		}
		if(j<n-1) {
		    count++;
		    sum += M[i][j+1];
		}
		if(i>0&&j<n-1) {
		    count++;
		    sum += M[i-1][j+1];
		}
		sum /= count;
		ret[i].push_back(sum);
	    }
	}
	return ret;
    }
};
