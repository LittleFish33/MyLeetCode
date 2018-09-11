class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
        	return 0;
		}
		else if(nums.size() == 1){
			return nums[0];
		}
		// 保存以A[i]结尾的子数组的最大值 
		vector<int> sum(nums.size());
		// 保存A[0], A[1], A[2], ... A[j]的子数组的最大值 
		vector<int> Max(nums.size());
        sum[0] = nums[0];
        Max[0] = nums[0];
		for(int i = 1;i < nums.size();i++) {
			sum[i] = max(sum[i-1]+nums[i],nums[i]);
			Max[i] = max(sum[i],Max[i-1]);
		}
		return Max[nums.size()-1];
    }
};