class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int length = nums.size();
	priority_queue<pair<int,int>> qu;
	vector<int> res;
	for (int i=0; i<k; ++i) {
	    qu.emplace(nums[i], i);
	}
	res.push_back(qu.top().first);
	for (int i=k; i<length; ++i) {
	    qu.emplace(nums[i], i);
	    while (qu.top().second<=i-k) {
	        qu.pop();
	    }
	    res.push_back(qu.top().first);
	}
	return res;
    }
};
