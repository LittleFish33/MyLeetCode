
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int left = 0,right = nums.size()-1,temp;
        for(int i = 0;i < nums.size();){
        	if(nums[i] == 0){
        		if(left == i){
        			i++;
        			left++;
				}
				else{
		    		temp = nums[left];
        			nums[left] = nums[i];
        			nums[i] = temp;
        			left++;	
				}
			}
			else if(nums[i] == 2){
				if(i >= right){
					break;
				}
				temp = nums[right];
        		nums[right] = nums[i];
        		nums[i] = temp;
        		right--;
			}
			else{
				i++;
			}
		}
    }
};