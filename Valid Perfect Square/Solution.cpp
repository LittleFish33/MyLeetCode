class Solution {
public:
    bool isPerfectSquare(int num) {
    	if(num == 1)return true;
		int left = 1,right = num/2,mid;
		while(left <= right){
			mid = left + (right - left)/2;
			if(num*1.0 / mid < mid){
				right = mid - 1;
			}
			else if(num*1.0 / mid > mid){
				left = mid + 1;
			}
			else{
				return true;
			}
		}
		return false;
    }
};
