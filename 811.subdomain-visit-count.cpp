class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string,int> map;
        for(int i=0;i<cpdomains.size();++i)
        {
            int pos = cpdomains[i].find(' ');
            int num = atoi(cpdomains[i].substr(0,pos).c_str());
            while(pos>0)
            {
                map[cpdomains[i].substr(pos+1)] += num;
                pos = cpdomains[i].find('.',pos+1);
            }
        }
        for(auto i=map.begin();i!=map.end();++i)
        {
            string s = to_string(i->second)+' '+i->first;
            res.push_back(s);
        }
        return res;
    }
};
