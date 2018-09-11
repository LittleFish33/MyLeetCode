class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(auto num : nums){
        	if(m.find(num) == m.end()){
        		m[num] = 1;
			}
			else{
				m[num]++;
			}
		}
		int max = 0,max_value = 0;
		for(auto value : m){
			if(value.second > max){
				max_value = value.first;
                max = value.second;
			}
		}
		return max_value;
    }
};
