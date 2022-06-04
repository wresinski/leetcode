class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int num = 1;
        for(int i=1;i<arr.size();++i)
        {
            if(arr[i]==arr[i-1]) num++;
            else num = 1;
            if(num*4>arr.size()) return arr[i];
        }
        return 1;
    }
};
