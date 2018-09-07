// 方法二：字典树实现 

// 字典树节点 
class TrieNode
{
public:
	TrieNode(char v = ' '){
		value = v;
		end = -1;
	};
	~TrieNode(){}
	unordered_map<char,TrieNode*> next;
	char value;
	int end; // 用于返回结尾的单词的编号是多少 
};

// 字典树类 
class Trie {
public:
    Trie() {
        head = new TrieNode();
    }
    
    ~Trie() {
        deleteNode(head);
    }
    
    void deleteNode(TrieNode* node){
    	if(node == nullptr){
    		return;
		}
		for(auto& n :node->next){
			deleteNode(n.second);
		}
		delete node;
	}
    
    // 插入节点 
    void insert(string word,int index) {
    	TrieNode* temp,*node = head;
        for(int i = 0;i < word.size();i++){
        	if(node->next.find(word[i]) == node->next.end()){
        		temp = new TrieNode(word[i]);
        		node->next[word[i]] = temp;
        		node = temp;
			}
			else{
				node = node->next[word[i]];
			}
		}
		node->end = index;
    }
    
    // 搜索匹配的回文对 
    vector<int> search(string word) {
        TrieNode* node = head;
        vector<int> ans;
        // 遍历字符串 
        for(int i = 0;i < word.size();i++){
        	// 搜索不到 
        	if(node->next.find(word[i]) == node->next.end()){
        		return ans;
			}
			// 搜素到，进入下一个字符 
			else{
				node = node->next[word[i]];
				if(node->end != -1){
				/*
				 考虑 "bb","b"的情况，此时存在：
				 		head
				 		 |
				 		 (b)
				 		 |
				 		 (b)
				 当word = "bb"的时候， 搜索到word[0]时，判断剩下的字符串 "b" 为 回文，
				 故 bb + b 为匹配的回文结果 
				 */
					if(i != word.size()-1 && is_Palindrome(word,i+1)){
						ans.push_back(node->end);
					}
				}
			}
		}
		// 搜索剩下的节点 
		searchRestNode(ans,node,"");
		return ans;
    }
    
    // 搜索一个节点剩下的节点 
    void searchRestNode(vector<int>& ans,TrieNode* node,string str){
    	if(node->end != -1){
    		/*
    		考虑 "ba","a"的情况，此时存在：
				 		head
				 		 |
				 		 (a)
				 		 |
				 		 (b)
			此时str = b, 为回文故可以构成回文 a + ba
    		*/
    		if(is_Palindrome(str)){
    		    ans.push_back(node->end);	
			}
		}
		for(auto& m : node->next){
			searchRestNode(ans,m.second,m.first + str);
		}
		
	}

	// 判断是否是回文	
	bool is_Palindrome(string& str,int begin = 0){
    	int end = str.size()-1;
    	while(begin < end)	{
    		if(str[begin] != str[end]){
    			return false;
			}
			begin++;
    		end--;
		}
		return true;
	}
	
private:
	TrieNode* head;
};


class Solution {
public:
	
    vector<vector<int>> palindromePairs(vector<string>& words) {
    	string str;
    	Trie trie;
    	vector<vector<int>> ans;
    	// 首先，先将所有字符串的反转结果保存起来 
    	for(int i = 0;i < words.size();i++){
    		str = words[i];
    		if(str == ""){
    			// 对于空串，空串 + 任何回文 = 回文；
				// 而对于回文+空串的情况 ，在下面对空串的遍历中已经会考虑到 
    			for(int j = 0;j < words.size();j++){
    				if(is_Palindrome(words[j]) && j != i){
    				    ans.push_back({j,i});		
					}
				}
			}
    		reverse(str.begin(),str.end());
    		trie.insert(str,i);
		}
		
		// 遍历所有字符串，寻找回文 
		for(int i = 0;i < words.size();i++){
			vector<int> result = trie.search(words[i]);
			for(int j = 0;j < result.size();j++) {
				if(i != result[j]){
					ans.push_back({i,result[j]});	
				}
			}
		} 
        return ans;
    }
    
    // 判断是否是回文
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
