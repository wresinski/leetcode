class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        //map.clear();
        /*
        for(int i=0;i<arr.size();++i)
        {
            map[arr[i]] = getOneCount(arr[i]);
        }
        */
        //递推预处理
        for(int i=0;i<10001;++i)
            bit[i] = bit[i>>1]+(i&1);
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
    /*
    int getOneCount(int num)
    {
        int res = 0;
        while(num>0)
        {
            res += num%2;
            num /= 2;
        }
        return res;
    }
    static bool compare(int x,int y)
    {
        if(map[x]<map[y]) return true;
        else if(map[x]>map[y]) return false;
        else return x<y;
    }
    static unordered_map<int,int> map;
    */
    //递推预处理
    static bool compare(int x, int y)
    {
        if(bit[x]<bit[y]) return true;
        else if(bit[x]>bit[y]) return false;
        else return x<y;
    }
    static int bit[10001];
};
/*
unordered_map<int,int> Solution::map;
*/
int Solution::bit[10001] = {0};
