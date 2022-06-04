class Solution {
public:
    string predictPartyVictory(string senate) {
        int size = senate.size();
        int banR = 0,banD = 0;
        while(1)
        {
            int countR = 0,countD = 0;
            for(int i=0;i<size;++i)
            {
                if(senate[i]=='R')
                {
                    if(banR>0)
                    {
                        senate[i] = 'o';
                        banR--;
                    }
                    else
                    {
                        banD++;
                        countR++;
                    }
                }
                else if(senate[i]=='D')
                {
                    if(banD>0)
                    {
                        senate[i] = 'o';
                        banD--;
                    }
                    else
                    {
                        banR++;
                        countD++;
                    }
                }
            }
            if(countR==0) return "Dire";
            if(countD==0) return "Radiant";
        }
    }
};
