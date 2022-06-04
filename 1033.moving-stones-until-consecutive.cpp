class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int temp;
        if(a>b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if(b>c)
        {
            temp = b;
            b = c;
            c = temp;
        }
        if(a>b)
        {
            temp = a;
            a = b;
            b = temp;
        }

        vector<int> res;
        if(b-a-1>1||c-b-1>1) res.push_back((b-a-1>1)+(c-b-1>1));
        else res.push_back(max(b-a-1,c-b-1));
        res.push_back(b-a-1+c-b-1);
        return res;
    }
};
