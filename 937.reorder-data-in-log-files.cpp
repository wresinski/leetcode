class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),compare);
        return logs;
    }
    static bool compare(const string &a,const string &b)
    {
        int blank_a = a.find(' ');
        int blank_b = b.find(' ');
        if(a[blank_a+1]>='0'&&a[blank_a+1]<='9') return false;
        if(b[blank_b+1]>='0'&&b[blank_b+1]<='9') return true;
        int com = a.compare(blank_a+1,-1,b,blank_b+1,-1);
        if(com>0) return false;
        else if(com<0) return true;
        else return a.compare(0,blank_a,b,0,blank_b)<=0;
    }
};
