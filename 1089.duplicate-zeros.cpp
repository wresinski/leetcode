class Solution {
public:
    /*
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        for(int i=0;i<arr.size();++i)
        {
            q.push(arr[i]);
            if(arr[i]==0) q.push(0);
            arr[i] = q.front();
            q.pop();
        }
    }
    */
    void duplicateZeros(vector<int>& arr) {
        int sum = 0,length = arr.size();
        int i = -1;
        while(sum<length){
            ++i;
            ++sum;
            if(arr[i]==0) ++sum;
        }
        if(sum>length){
            --i;
            arr[--length] = 0;
        }
        length--;
        for(;i>=0;--i) {
            arr[length--] = arr[i];
            if(arr[i]==0) arr[length--] = 0;
        }
    }
};
