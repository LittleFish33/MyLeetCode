class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)return 0;
    	int array[255],temp,max = INT_MIN,cur = 0;
		memset(array,-1,sizeof(int)*255);
		for(int i = 0;i < s.size();i++){
			temp = array[s[i]];
			if(temp == -1 || i - temp > cur){  // "abba"的情况
				cur++;
			}
			else{
				cur = i - temp;
			}
			array[s[i]] = i;
			if(max < cur){
				max = cur;
			}
		}
		return max;
    }
};
 