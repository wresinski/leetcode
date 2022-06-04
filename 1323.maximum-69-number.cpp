class Solution {
public:
    int maximum69Number (int num) {
        for(int i=10000;i>1;i/=10)
        {
            if((num%i)/(i/10)==6)
            {
                num += i/10*3;
                break;
            }
        }
        return num;
    }
};
