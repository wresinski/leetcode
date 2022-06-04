class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i=0;i<tokens.size();++i)
        {
            string num = tokens[i];
            if(num=="+"||num=="-"||num=="*"||num=="/")
            {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if(num=="+") nums.push(num1+num2);
                if(num=="-") nums.push(num1-num2);
                if(num=="*") nums.push(num1*num2);
                if(num=="/") nums.push(num1/num2);
            }
            else
            {
                nums.push(atoi(num.c_str()));
            }
        }
        return nums.top();
    }
};
