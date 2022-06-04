class Solution {
public:
    /*
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return intersect(nums2,nums1);
        std::unordered_map<int,int> map;
        std::vector<int> result;
        for(int i=0;i<nums1.size();++i)
        {
            map[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();++i)
        {
            if(map[nums2[i]]>0)
            {
                result.push_back(nums2[i]);
                map[nums2[i]]--;
            }
        }
        return result;
    }
    */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ret;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int length1 = nums1.size();
	int length2 = nums2.size();
	int i = 0, j = 0;
	while (i<length1&&j<length2) {
	    if(nums1[i]<nums2[j]) i++;
	    else if(nums1[i]>nums2[j]) j++;
	    else {
		ret.push_back(nums1[i]);
		i++;
		j++;
	    }
	}
	return ret;
    }
};
