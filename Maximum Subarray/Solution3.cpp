class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
        	return 0;
		}
		else if(nums.size() == 1){
			return nums[0];
		}
        // sun保存以A[i]结尾的子数组的最大值 
        int sum = nums[0];
        // Max保存A[0], A[1], A[2], ... A[j]的子数组的最大值 
        int Max = nums[0];
		for(int i = 1;i < nums.size();i++) {
			sum = max(sum+nums[i],nums[i]);
			Max = max(sum,Max);
		}
		return Max;
    }
};