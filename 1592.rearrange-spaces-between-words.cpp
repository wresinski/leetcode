class Solution {
public:
    string reorderSpaces(string text) {
        string temp;
        vector<string> array;
        int num = 0;
        for(int i=0;i<text.size();++i)
        {
            if(text[i]==' ')
            {
                num++;
                if(temp.size()!=0)
                {
                    array.push_back(temp);
                    temp.clear();
                }
            }
            else
            {
                temp += text[i];
            }
        }
        if(temp.size()!=0)
        {
            array.push_back(temp);
            temp.clear();
        }
        int a = array.size()>1?num/(array.size()-1):0;
        int b = num-(array.size()-1)*a;
        for(int i=0;i<array.size();++i)
        {
            temp += array[i];
            if(i!=array.size()-1) temp += string(a,' ');
            else temp += string(b,' ');
        }
        return temp;
    }
};
