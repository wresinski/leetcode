class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = 0,pre = 0;
        string res;
        while(i<num1.size()||i<num2.size()||pre)
        {
            int x1 = i<num1.size()?(num1[num1.size()-1-i]-'0'):0;
            int x2 = i<num2.size()?(num2[num2.size()-1-i]-'0'):0;
            int sum = x1+x2+pre;
            pre = 0;
            if(sum>=10)
            {
                sum -= 10;
                pre++;
            }
            res = (char)(sum+'0')+res;
            i++;
        }
        return res;
    }
};
