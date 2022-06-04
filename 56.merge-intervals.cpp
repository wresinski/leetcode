class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> res;
	for (auto& pair : intervals) {
	    if (!res.empty()&&pair[0]<=res.back()[1]) {
		res.back()[1] = max(res.back()[1], pair[1]);
	    }
	    else {
		res.emplace_back(pair);
	    }
	}
	return res;
    }
};
