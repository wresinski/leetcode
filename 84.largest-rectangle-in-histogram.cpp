class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
	int max = 0;
	int length = heights.size();
	stack<int> s;
	int* lr = new int[length];
	int* rl = new int[length];
	for(int i=0;i<length;++i) rl[i] = length;
	for(int i=0;i<length;++i) {
	    while(!s.empty()&&heights[s.top()]>=heights[i]) {
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
	for(int i=0;i<length;++i) {
	    int temp = heights[i]*(rl[i]-lr[i]-1);
	    if(temp>max) max = temp;
	}
	delete[] lr;
	delete[] rl;
	return max;
    }
};
