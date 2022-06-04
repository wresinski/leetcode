class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();++i)
        {
            if(isEven(nums[i])) res++;
        }
        return res;
    }
    bool isEven(int num)
    {
        int i = 0;
        while(num>0)
        {
            num /= 10;
            i++;
        }
        return !(i%2);
    }
};
