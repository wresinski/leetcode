class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i=1;i<n;++i)
        {
            string strTemp;
            char temp;
            int count = 0;
            for(int j=0;j<res.size();++j)
            {
                if(res[j]!=temp)
                {
                    if(count>0) strTemp = strTemp+(char)(count+'0')+temp;
                    temp = res[j];
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            strTemp = strTemp+(char)(count+'0')+temp;
            res = strTemp;
        }
        return res;
    }
};
