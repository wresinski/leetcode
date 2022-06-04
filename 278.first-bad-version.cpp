// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
	int low = 1;
	int high = n;
	while (low<=high) {
	    int mid = low+(high-low)/2; // 防止计算时溢出
	    if(isBadVersion(mid)) high = mid - 1;
	    else low = mid + 1;
	}
	return low;
    }
};
