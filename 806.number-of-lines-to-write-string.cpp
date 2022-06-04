class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1;
        int last = 0;
        for(int i=0;i<S.size();++i)
        {
            if(last+widths[S[i]-'a']<=100) last += widths[S[i]-'a'];
            else
            {
                line++;
                last = widths[S[i]-'a'];
            }

        }
        return vector<int>{line,last};
    }
};
