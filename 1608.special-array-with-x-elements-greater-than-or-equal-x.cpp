class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int pre = 0;
        int count = nums.size();
        for(int i=0;i<count;++i)
        {
            int res = count-i;
            if(res>pre&&res<=nums[i]) return res;
            pre = nums[i];
        }
        return -1;
    }
};
