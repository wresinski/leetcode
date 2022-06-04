class Solution {
public:
    int maxArea(vector<int>& height) {
	int right = 0, left = height.size()-1;
	int res = 0;
	while (right<left) {
	    res = max(res, min(height[right], height[left])*(left-right));
	    if (height[right]<height[left]) {
		++right;
	    }
	    else {
		--left;
	    }
	}
	return res;
    }
};
