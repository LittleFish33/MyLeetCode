class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> ori(nums);
        vector<int> ans(2);
        sort(nums.begin(),nums.end());
        int left = 0,right = nums.size()-1;
        while(left <= right){
        	if(nums[left] + nums[right] > target){
        		right--;
			}
			else if(nums[left] + nums[right] < target){
				left++;
			}
			else{
				int j = 0;
				for(int i = 0;i < ori.size();i++){
					if(ori[i] == nums[left] || ori[i] == nums[right]){
						ans[j++] = i;
					}
				}
				break;
			}
		} 
		return ans;
    }
};