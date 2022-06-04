/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int res = 1;
        int min = 1;
        int mid;
        while(res!=0)
        {
            mid = min+(n-min)/2;
            res = guess(mid);
            if(res==-1) n = mid-1;
            else if(res==1) min = mid+1;
        }
        return mid;
    }
};
