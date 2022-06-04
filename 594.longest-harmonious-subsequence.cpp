class Solution {
public:
    int findLHS(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	int res = 0;
	int t[2] = {0,-1};
	for(int i=1;i<nums.size();++i) {
	    if((nums[i]-nums[i-1]>0)&&t[1]!=-1) res = max(res,i-t[0]);
	    if(nums[i]-nums[i-1]==1) {
		if(t[1]!=-1) {
		    t[0] = t[1];
		}
		t[1] = i;
	    }
	    else if(nums[i]-nums[i-1]>1) {
		t[0] = i;
		t[1] = -1;
	    }
	}
	if(t[1]!=-1) res = max(res,(int)nums.size()-t[0]);
	return res;
    }
    /*
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        int res = 0;
        for(int i=0;i<nums.size();++i)
        {
            map[nums[i]]++;
            res = max(res,map[nums[i]+1]>0?map[nums[i]]+map[nums[i]+1]:0);
            res = max(res,map[nums[i]-1]>0?map[nums[i]]+map[nums[i]-1]:0);
        }
        return res;
    }
    */
};
