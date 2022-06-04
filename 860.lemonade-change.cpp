class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int nFive = 0,nTen = 0;
        for(int i=0;i<bills.size();++i)
        {
            if(bills[i]==5) 
            {
                nFive++;
            }
            else if(bills[i]==10)
            {
                if(nFive>0)
                {
                    nFive--;
                    nTen++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(nFive>0&&nTen>0)
                {
                    nFive--;
                    nTen--;
                }
                else if(nFive>=3)
                {
                    nFive -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
