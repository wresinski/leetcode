class Solution {
public:
    int findComplement(int num) {
        int n = num;
        int i = 0;
        while(n) 
        {
            n>>=1;
            i++;
        }
        return num^((long)(1<<i)-1);
            

        //int res = 0;
        //int i = 1;
        //while(num>0)
        //{
        //    res += !(num%2)*i;
        //    if(i<1073741824) i *= 2;
        //    num /= 2;
        //}
        //return res;
    }
};
