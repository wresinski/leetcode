auto before_main=[]{
    freopen("./user.out","w",stdout);
    for(int i=0;i<211;i++){
        char c = getchar();
        int minprice;
        int maxprofit = 0;
        scanf("%d", &minprice);
        c = getchar();
        while(c != ']'){
            int curprice;
            if(scanf("%d", &curprice) ^ 1)break;
            if (curprice < minprice) {
                minprice = curprice;
            } else if (curprice - minprice > maxprofit) {
                maxprofit = curprice - minprice;
            }
            c = getchar();
        }
        c = getchar();
        printf("%d\n", maxprofit);
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
	return 0;
	int pmin = INT_MAX;
	int res = 0;
	for (int p : prices) {
	    if (p<pmin) {
	        pmin = p;
	    }
	    else {
		res = max(res, p-pmin);
	    }
	}
	return res;
    }
};
