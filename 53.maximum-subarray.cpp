class Solution {
public:
    // 动态规划
    int maxSubArray(vector<int>& nums) {
	int res = nums[0];
	int pre = nums[0];
	for(int i=1;i<nums.size();++i) {
	    int temp = (pre+nums[i])>nums[i]?(pre+nums[i]):nums[i];
	    pre = temp;
	    if(temp>res) res = temp;
	}
	return res;
    }
    /*
    int maxSubArray(vector<int>& nums) {
        int nMin = 0,nMax = nums[0],sum = 0;
        int res = nums[0];
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i];
            if(nMax<sum)
            {
                nMax = sum;
            }
            if(nMin>sum&&i!=nums.size()-1) 
            {
                nMin = sum;
                nMax = sum+nums[i+1];
            }
            if(res<nMax-nMin) res = nMax-nMin;
        }
        return res;
    }
    */
};
