// 方法一的实现
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> reverse_map;
        string reverseStr; 
        //先将所有字符串反转后的结果保存起来，便于之后查找 
        for(int i = 0;i < words.size();i++){
        	reverseStr = words[i];
        	reverse(reverseStr.begin(),reverseStr.end());
        	reverse_map.insert({reverseStr,i});
		}

		vector<vector<int>> ans;
		string left,right;
		for(int i = 0;i < words.size();i++) {
			for(int j = 0; j <= words[i].size();j++){
				// 将当前字符串拆分为两个部分：left和right
				// left: 空串到整个字符串
				// right: 整个字符串到空串 
				left = words[i].substr(0,j);
				right=words[i].substr(j, words[i].size()-j);
				/*
				如果该字符串 + 另一个字符串能构成回文，那么right为回文，即left + right + word2构成一个回文对，
				此时在字符串组里查找是否存在 word2 等于left反转后的结果
				*/
				if(is_Palindrome(right)){
					if(reverse_map.find(left) != reverse_map.end() && reverse_map[left] != i){
						ans.push_back({i,reverse_map[left]});
					}
				}
				/*
				* 同理对 word2 + left + right 进行分析 
				*/ 
				if(is_Palindrome(left)){
					//left != "" 避免重复的对
					if(reverse_map.find(right) != reverse_map.end() && reverse_map[right] != i && left != ""){
						ans.push_back({reverse_map[right],i});
					}
				}
			}
		}
		return ans;
    }
    
    bool is_Palindrome(string& str){
    	int begin = 0,end = str.size()-1;
    	while(begin < end)	{
    		if(str[begin] != str[end]){
    			return false;
			}
			begin++;
    		end--;
		}
		return true;
	}
    
};






