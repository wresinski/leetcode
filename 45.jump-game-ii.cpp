class Solution {
public:
    // 正向
    int jump(vector<int>& nums) {
	int n = nums.size();
	int count = 0;
	int max_dis = 0;
	int dis = min(nums[0],n-1);
	for (int i=1; i<n; ++i) {
	    max_dis = max(max_dis,i+nums[i]);
	    if (i==dis) {
	        dis = min(max_dis,n-1);
		count++;
	    }
	}
	return count;
    }
    /*
    int jump(vector<int>& nums) {
	int n = nums.size();
	int i = 0;
	int count = 0;
	int max_dis = 0;
	while (i<n-1) {
	    count++;
	    int dis = i+nums[i];
	    if (dis>=n-1) break;
	    for (int j=i+1; j<=dis&&j<n; ++j) {
		if (max_dis<j+nums[j]) {
		    max_dis = j+nums[j];
		    i = j;
		}
            }
        }
	return count;
    }
    */
    /*
    // 逆向
    int jump(vector<int>& nums) {
	int n = nums.size();
	int i = n-1;
	int count = 0;
	while (i!=0) {
	    for (int j=0; j<i; ++j) {
		if (nums[j]+j>=i) {
		    i = j;
		    count++;
		    break;
		}
	    }
	}
	return count;
    }
    */
};
