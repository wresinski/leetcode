class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int iLength = INT_MAX;
        int iDegree = 0;
        std::unordered_map<int,int> mapDegree,mapStart;
        for(int i=0;i<nums.size();++i)
        {
            if(!mapDegree[nums[i]]) mapStart[nums[i]] = i;
            mapDegree[nums[i]]++;
            if(mapDegree[nums[i]]>iDegree)
            {
                iDegree = mapDegree[nums[i]];
                iLength = i-mapStart[nums[i]]+1;
            }
            else if(mapDegree[nums[i]]==iDegree)
                iLength = min(iLength,i-mapStart[nums[i]]+1);
        }
        return iLength;
    }
};
