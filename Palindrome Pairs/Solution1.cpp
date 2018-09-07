// ����һ��ʵ��
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> reverse_map;
        string reverseStr; 
        //�Ƚ������ַ�����ת��Ľ����������������֮����� 
        for(int i = 0;i < words.size();i++){
        	reverseStr = words[i];
        	reverse(reverseStr.begin(),reverseStr.end());
        	reverse_map.insert({reverseStr,i});
		}

		vector<vector<int>> ans;
		string left,right;
		for(int i = 0;i < words.size();i++) {
			for(int j = 0; j <= words[i].size();j++){
				// ����ǰ�ַ������Ϊ�������֣�left��right
				// left: �մ��������ַ���
				// right: �����ַ������մ� 
				left = words[i].substr(0,j);
				right=words[i].substr(j, words[i].size()-j);
				/*
				������ַ��� + ��һ���ַ����ܹ��ɻ��ģ���ôrightΪ���ģ���left + right + word2����һ�����Ķԣ�
				��ʱ���ַ�����������Ƿ���� word2 ����left��ת��Ľ��
				*/
				if(is_Palindrome(right)){
					if(reverse_map.find(left) != reverse_map.end() && reverse_map[left] != i){
						ans.push_back({i,reverse_map[left]});
					}
				}
				/*
				* ͬ��� word2 + left + right ���з��� 
				*/ 
				if(is_Palindrome(left)){
					//left != "" �����ظ��Ķ�
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






