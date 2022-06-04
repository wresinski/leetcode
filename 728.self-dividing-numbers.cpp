class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;++i)
        {
           if(isSelfDiving(i)) res.push_back(i);
        }
        return res;
    }
    bool isSelfDiving(int num)
    {
        int temp = num;
        while(temp>0)
        {
            int i = temp%10;
            if(i==0||num%i!=0) return false;
            temp /= 10;
        }
    return true;
    }
};
