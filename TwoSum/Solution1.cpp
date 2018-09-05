class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> temp(nums.size());
    	vector<int> ori(nums);
        mergeSortVector(nums,0,nums.size()-1,temp); 
        int left = 0,right = nums.size()-1;
        vector<int> ans(2);
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
    void mergeSortVector(vector<int>& nums,int low,int high,vector<int>& temp){
    	if(low < high){
    		int mid = (low + high) /2;
    		mergeSortVector(nums,low,mid,temp);
    		mergeSortVector(nums,mid+1,high,temp);
    		merge(nums,low,mid,high,temp);
		}
	}
	void merge(vector<int>& nums,int low,int mid,int high,vector<int>& temp){
		int i = low,j = mid +1,k = low;
		while(i <= mid && j <= high){
			if(nums[i] > nums[j]){
				temp[k++] = nums[j++];
			}
			else{
				temp[k++] = nums[i++];
			}
		}
		while(i <= mid){
			temp[k++] = nums[i++];
		}
		while(j <= high){
			temp[k++] = nums[j++];
		}
		for(int i = low;i <= high;i++){
			nums[i] = temp[i];
		}
	}
	
};