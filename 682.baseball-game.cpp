class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<int> st;
        for(int i=0;i<ops.size();++i)
        {
            if(ops[i]=="+") 
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num1);
                st.push(num1+num2);
		res += num1+num2;
            }
            else if(ops[i]=="D") {
		res += st.top()*2;
		st.push(st.top()*2);
	    }
            else if(ops[i]=="C") {
		res -= st.top();
		st.pop();
	    }
            else 
            {
                st.push(stoi(ops[i]));
		res += stoi(ops[i]);
            }
        }
        return res;
    }
};
