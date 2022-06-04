class Solution {
public:
    /*
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();++i)
        {
            if(map[nums[i]]!=0&&i+1-map[nums[i]]<=k) return true;
            map[nums[i]] = i+1;
        }
        return false;
    }
    */
  //滑动窗口
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
      int length = nums.size();
      unordered_map<int, int> m;
      for (int i = 0; i < length; ++i) {
	  if (i > k)
	      m[nums[i - k - 1]]--;
	  if (m[nums[i]] > 0)
	      return true;
          m[nums[i]]++;
      }
      return false;
  }
};
