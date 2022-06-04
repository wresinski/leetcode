class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int iMax = -1;
        for(int i=arr.size()-1;i>=0;--i)
        {
            int temp = arr[i];
            arr[i] = iMax;
            if(temp>iMax) iMax = temp;
        }
        return arr;
    }
};
