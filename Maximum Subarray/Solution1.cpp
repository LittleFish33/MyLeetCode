class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
        	return 0;
		}
        return getMax(nums,0,nums.size()-1);
    }
    
    // 求连续子数组的最大值 
    int getMax(vector<int>& nums, int begin, int end){
    	// 结束条件： begin == end，子数组的大小为 1 
    	if(begin == end){
    		return nums[end];
		}
		int mid = (begin + end)/2;
		// 左边的连续子数组的最大值 
		int maxLeft = getMax(nums, begin, mid);
		// 右边的连续子数组的最大值 
		int maxRight = getMax(nums, mid+1,end);
		// 跨越中间的连续子数组的最大值  
		int maxMid = getMaxMid(nums, begin, mid, end);
		// 取上面三者的最大值 
		return max(max(maxLeft, maxRight),maxMid);
	}
	
	// 求跨越中间的连续子数组的最大值  
	int getMaxMid(vector<int>& nums, int begin, int mid, int end){
		int leftMax = nums[mid],rightMax = nums[mid+1];
		int sum = 0;
		// 从中间的元素向左找以nums[mid]结尾的最大子数组 
		for(int i = mid;i >= begin;i--){
			sum += nums[i];
			if(sum > leftMax){
				leftMax = sum;
			}
		}
		sum = 0;
		// 从中间的元素向右找以nums[mid]结尾的最大子数组 
		for(int i = mid+1;i <= end;i++){
			sum	+= nums[i];
			if(sum > rightMax){
				rightMax = sum;
			}
		}
		return leftMax + rightMax;
	}
};