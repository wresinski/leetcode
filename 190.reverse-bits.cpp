class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
     uint32_t res;
     res = reverseByte((n&0xff000000)>>24)
     | reverseByte((n&0x00ff0000)>>16)<<8
     | reverseByte((n&0x0000ff00)>>8)<<16
     | reverseByte(n&0x000000ff)<<24;
     return res;
    }
    uint32_t reverseByte(uint32_t n)
    {
        int res = cache[n];
        if(!res)
        {
            res = (n*0x0202020202ULL&0x010884422010ULL)%1023;
            cache[n] = res;
        }
        return res;
    }
private:
    map<uint32_t,uint32_t> cache;
};

//012345678 012345678 012345678 012345678
//    12345 678123456 781234567 812345678
