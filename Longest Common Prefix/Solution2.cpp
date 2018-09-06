const int MAX = 26;
// 字典树节点类
class TrieNode
{
public:
	TrieNode* next[MAX];
	int value,nextSize;
	TrieNode(int v = 0,int s = 0){
		value = v;
		nextSize = s;
		for(int i = 0;i < MAX;i++){
			next[i] = nullptr;
		}
	}
};

class Trie
{
public:
	Trie(){
		head = new TrieNode();
	}
	~Trie(){
		deleteNode(head);
	}

	// 释放节点
	void deleteNode(TrieNode* node){
		if(node == nullptr){
			return;
		}
		for(int i = 0;i < MAX;i++){
			deleteNode(node->next[i]);
		}
		delete node;
	}

	// 往字典树中插入字符串
	void insert_str(string str){
		TrieNode* temp,*p = head;
		for (int i = 0; i < str.size(); ++i)
		{
			int c = str[i] - 'a';
			// 如果不存在子节点，新建节点，并将p指向新节点
			if(!p->next[c]){
				temp = new TrieNode(c,0);
				p->next[c] = temp;
				p->nextSize++;
				p = p->next[c];
			}
			// 如果存在子节点，直接将p指向新节点
			else{
				p = p->next[c];
			}
		}
	}

	// 搜索最长前缀，需要输入字符串组中长度最小的字符串
	string searchLongestPrefix(string word){
		string ans = "";
		TrieNode* p = head;
		int j = 0;
		while(p!= nullptr && p->nextSize == 1 && j < word.size()){
			ans+= word[j];
			p = p->next[word[j]- 'a'];
			j++;
		}
		return ans;
	}


private:
	TrieNode* head;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size() == 0){
    		return "";
		}
		else if(strs.size() == 1){
			return strs[0];
		}
		Trie trie;
		string shortest = strs[0];
        for(int i = 0;i < strs.size();i++){
        	if(shortest.size() > strs[i].size()){
        		shortest = strs[i];
			}
        	trie.insert_str(strs[i]);
		}
		return trie.searchLongestPrefix(shortest);
    }
};
