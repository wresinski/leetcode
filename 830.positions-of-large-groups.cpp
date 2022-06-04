class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        vector<int> temp;
        temp.resize(2);
        int length = 1;
        for(int i=1;i<=s.size();++i)
        {
            if(i!=n&&s[i]==s[i-1]) length++;
            else
            {
                if(length>=3)
                {
                    temp[0] = i-length;
                    temp[1] = i-1;
                    result.push_back(temp);
                }
                length = 1;
            }
        }
        return result;
    }           
};
