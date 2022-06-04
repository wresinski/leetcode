class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min = INT_MAX;
        int sum = 0;
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i];
            if(sum<min) min = sum;
        }
        return (1-min)>0?1-min:1;
    }
};
