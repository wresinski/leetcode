class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        unordered_map<int,int> map;
        sort(temp.begin(),temp.end());
        int n = 0;
        for(int i=0;i<temp.size();++i)
        {
            if(map[temp[i]]==0) map[temp[i]] = ++n;
        }
        for(int i=0;i<arr.size();++i)
        {
            arr[i] = map[arr[i]];
        }
        return arr;
    }
};
