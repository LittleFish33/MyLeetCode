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
	bool search(string word,int index){
		if(word.size() == index){
			return end;
		}
		if(word[index] == '.'){
			for(int i = 0;i < MAX;i++){
				if(next[i] != nullptr && next[i]->search(word,index+1)){
					return true; 
				}
			}
			return false;
		}
		else{
			int ch = word[index] - 'a';
			if(next[ch] == nullptr){
				return false;
			}
			else{
				return next[ch]->search(word,index+1);
			}
		}
		
	}
	
	TrieNode* next[MAX];
	int value;
	bool end;
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new TrieNode();
    }
    
    ~WordDictionary() {
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
	
    /** Adds a word into the data structure. */
    void addWord(string word) {
    	int ch;
    	TrieNode* temp,*node = head;
        for(int i = 0;i < word.size();i++) {
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
    	if(word.size() == 0){
    		return false;
		}
		return head->search(word,0);
    }
    
private:
	TrieNode* head;
    	
};

