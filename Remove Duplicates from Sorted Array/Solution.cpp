class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() == 0){
    		return 0;
		}
		int max = nums[0],number = 1;
		for(int i = 1;i < nums.size();i++){
			if(nums[i] > max){
				nums[number] = nums[i];
				number++;
				max = nums[i];
			}
		}
		return number;
    }
};
