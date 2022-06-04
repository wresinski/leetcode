class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end(),[](int x, int y)->bool{ return x>y; });
        while(stones.size()>1)
        {
            int temp = stones[0]-stones[1];
            if(temp>0)
            {
                stones.erase(stones.begin());
                stones[0] = temp;
                sort(stones.begin(),stones.end(),[](int x, int y)->bool{ return x>y; });
            }
            else
            {
                stones.erase(stones.begin());
                stones.erase(stones.begin());
            }
        }
        return stones.size()>0?stones[0]:0;
    }
};
