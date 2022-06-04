class NumArray {
public:
    NumArray(vector<int>& nums) {
	int size = nums.size();
	int sum = 0;
	for(int i=0;i<size;++i) {
	    sum += nums[i];
	    m_vecNums.push_back(sum);
	}
    }
    
    int sumRange(int i, int j) {
	if(i==0) return m_vecNums[j];
        return m_vecNums[j]-m_vecNums[i-1];
    }
private:
    vector<int> m_vecNums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
