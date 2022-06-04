class Solution {
public:
    //巴克斯范式
    //String→Digits[String]String∣AlphaString∣ϵ
    //Digits→DigitDigits∣Digit
    //Alpha→a∣⋯∣z∣A∣⋯∣Z
    //Digit→0∣⋯∣9
    //递归
    string decodeString(string s) {
	int i = 0;
	return helper(s, i);
    }
    int getDigit(string &s, int &index) {
	string num;
	while(isdigit(s[index])) {
	    num += s[index];
	}
	return atoi(num.c_str());
    }
    string getString(string &s, int &index) {
	if(index==s.size()||s[index]==']') return "";
	string ret;
	if(isdigit(s[index])) {
	    int n = getDigit(s, index);
	    index++;
	    string tmp = getString(s, index);
	    index++;
	    while (n--) {
		ret += tmp; 
	    }
	}
	else {
	    ret += s[index];
	}
	return ret + getString(s, index);
    }
    string helper(string &s, int &index) {
	int length = s.size();
	string num;
	string str,tmp;
	while(index<length) {
	    if(isdigit(s[index])) {
		num += s[index];
	    }
	    else if(s[index]=='[') {
		tmp = helper(s, ++index);
		int n = atoi(num.c_str());
		num.clear();
		while(n--) {
		    str += tmp;
		}
	    }	
	    else if(s[index]==']') {
		break;
	    }
	    else {
		str += s[index];
	    }
	    index++;
	}
	return str;
    }
    /*
    string decodeString(string s) {
        vector<string> vec;
        stack<int> st;
        string num;
        string str;
        for(int i=0;i<s.size();++i)
        {
            if(isdigit(s[i]))
            {
                num += s[i];
            }
            else if(s[i]=='[')
            {
                vec.push_back(str);
                str.clear();
                st.push(atoi(num.c_str()));
                num.clear();
            }
            else if(s[i]==']')
            {
                string pre = vec.back();
                vec.pop_back();
                for(int j=0;j<st.top();++j)
                {
                    pre += str;
                }
                st.pop();
                str = pre;
            }
            else
            {
                str += s[i];
            }
        }
        return str;
    }
    */
    /*
    string decodeString(string s) {
	stack<string> st;
	string num;
	string str;
	for(int i=0;i<s.size();++i) {
	    if(isdigit(s[i])) {
		num += s[i];
	    }
	    else if(s[i]=='[') {
		st.push(str);
		str.clear();
		st.push(num);
		num.clear();
	    }
	    else if(s[i]==']') {
		int n = atoi(st.top().c_str());
		st.pop();
		string temp = st.top();
		st.pop();
		for(int j=0;j<n;++j) {
		    temp += str;
		}
		str = temp;
	    }
	    else {
		str += s[i];
	    }
	}
	return str;
    }
    */
    //官方题解一：栈操作
    /*
    string decodeString(string s) {
	string res;
	stack<string> st;
	string num;
	for(int i=0;i<s.size();++i) {
	    if(isdigit(s[i])) {
		num += s[i];
	    }
	    else if(s[i]=='[') {
		st.push(num);
		num.clear();
		st.push("[");
	    }
	    else if(s[i]==']') {
		string str;
		string temp = st.top();
		st.pop();
		while(temp!="[") {
		    str = temp + str; 
		    temp = st.top();
		    st.pop();
		}
		int n = atoi(st.top().c_str());
		st.pop();
		temp.clear();
		for(int j=0;j<n;++j) {
		    temp += str;
		}
		st.push(temp);
	    }
	    else {
		st.push(string(1,s[i]));
	    }
	}
	while(!st.empty()) {
	    res = st.top() + res; 
	    st.pop();
	}
	return res;
    }
    */
};
