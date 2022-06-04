class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i];
        }
        int right = 0;
        for(int i=0;i<nums.size();++i)
        {
            if(sum-right-nums[i]==right) return i;
            right += nums[i];
        }
        return -1;
    }
};
