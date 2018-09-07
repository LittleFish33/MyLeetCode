const int MAX = 26;

class TrieNode
{
public:
	TrieNode(int v = 0){
		value = v;
		for(int i = 0;i < MAX;i++){
			next[i] = nullptr;
		}
		end = false;
	};
	~TrieNode(){}
	TrieNode* next[MAX];
	int value,size;
	bool end;
};


class Trie {
public:
    /** Initialize your data structure here. */
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
    	for(int i = 0;i < MAX;i++){
    		deleteNode(node->next[i]);
		}
		delete node;
	}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	TrieNode* temp,*node = head;
    	int ch;
        for(int i = 0;i < word.size();i++){
        	ch = word[i] - 'a';
        	if(node->next[ch] == nullptr){
        		temp = new TrieNode(ch);
        		node->next[ch] = temp;
        		node = temp;
			}
			else{
				node = node->next[ch];
			}
		}
		node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = head;
        for(int i = 0;i < word.size();i++){
        	if(node->next[word[i]-'a'] == nullptr){
        		return false;
			}
			else{
				node = node->next[word[i]-'a'];
			}
		}
		return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = head;
        for(int i = 0;i < prefix.size();i++){
        	if(node->next[prefix[i]-'a'] == nullptr){
        		return false;
			}
			else{
				node = node->next[prefix[i]-'a'];
			}
		}
		return true;
    }

private:
	TrieNode* head;
};
