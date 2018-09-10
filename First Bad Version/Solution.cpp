// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 0)return 0;
        int low = 1,high = n,mid;
        while(low <= high){
        	mid = low + (high - low)/2;
        	if(isBadVersion(mid)){
        		if(mid == 1 || !isBadVersion(mid-1)){
        			return mid;
				}
				else{
					high = mid-1;
				}
			}
			else{
				low = mid+1;
			}
		}
        return 0;
    }
};