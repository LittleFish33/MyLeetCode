class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	// 超过 n/3 的数，最多只有两个 
		int count1 = 0,value1 = 0,count2 = 0,value2 = 0;
		for(int i = 0;i < nums.size();i++){
			if(value1 == nums[i]){
				count1++;
			}
			else if(value2 == nums[i]){
				count2++;
			}
			else if(count1 == 0){
				value1 = nums[i];
				count1++;
			}
			else if(count2 == 0){
				value2 = nums[i];
				count2++;
			}
			else{
				count1--;
				count2--;
			}
		}
		count1 = 0;
		count2 = 0;
		for(int i = 0; i < nums.size();i++){
			if(nums[i] == value1){
				count1++;
			}
			else if(nums[i] == value2){
				count2++;
			}
		}
		vector<int> res;
		if(count1 > nums.size()/3){
			res.push_back(value1);
		}
		if(count2 > nums.size()/3){
			res.push_back(value2);
		}
		return res;
    }
};
