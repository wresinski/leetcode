class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int map[26] = {0};
        for(int i=0;i<text.size();++i)
        {
            ++map[text[i]-'a'];
        }
        int MAX = INT_MAX;
        MAX = min(map['b'-'a'],MAX);
        MAX = min(map['a'-'a'],MAX);
        MAX = min(map['l'-'a']/2,MAX);
        MAX = min(map['o'-'a']/2,MAX);
        MAX = min(map['n'-'a'],MAX);
        return MAX;
    }
};
