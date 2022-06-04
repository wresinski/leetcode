class Solution {
public:
    /*
    // Solution1
    vector<int> countBits(int n) {
	vector<int> res(n+1,0);
	int high = 0;
	for(int i=1;i<=n;++i) {
	    if((i&i-1)==0) {
		res[i] = 1;
		high = i;
	    }
	    else {
		res[i] = res[i-high] + 1;
	    }
	}
	return res;
    }
    */
    /*
    // Solution2
    vector<int> countBits(int n) {
	vector<int> res(n+1,0);
	for(int i=1;i<=n;++i) {
	    res[i] = res[i>>1] + i%2;
	}
	return res;
    }
    */
    // Solution3
    vector<int> countBits(int n) {
	vector<int> res(n+1,0);
	for(int i=1;i<=n;++i) {
	    res[i] = res[i&(i-1)] + 1;
	}
	return res;
    }
};
