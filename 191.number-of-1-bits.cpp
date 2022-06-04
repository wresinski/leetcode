class Solution {
public:
    // 优化：n&(n-1)相当于将最低位的1置0 
    int hammingWeight(uint32_t n) {
	int res = 0;
	while (n) {
	    n = n&(n-1);
	    res++;
	}
	return res;
    }
    /*
    int hammingWeight(uint32_t n) {
	int res = 0;
	for(int i=0;i<32;++i) {
	    if((n>>i)&1) res++;
	}
	return res;
    }
    */
};
