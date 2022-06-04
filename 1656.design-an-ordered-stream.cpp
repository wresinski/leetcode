class OrderedStream {
public:
    OrderedStream(int n) {
        vec.resize(n);
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> res;
        vec[id-1] = value;
        if(id==ptr)
        {
            for(;ptr<=vec.size();++ptr)
            {
                if(vec[ptr-1].size()>0) res.push_back(vec[ptr-1]);
                else break;
            }
        }
        return res;
    }
private:
    int ptr;
    vector<string> vec;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
