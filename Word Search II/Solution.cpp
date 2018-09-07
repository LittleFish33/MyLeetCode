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
	int value;
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
    
    TrieNode* getHead(){
    	return head;
	}

private:
	TrieNode* head;
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); ++i)
        {
        	trie.insert(words[i]);
        }
        set<string> result_set;
        length = board.size();
		width = board[0].size();
        for(int i = 0;i < length;i++){
        	for(int j = 0;j < width;j++){
        		bool flag[length * width];
        		memset(flag,0,length * width);
				findpath(result_set,board,flag,i,j,trie.getHead(),"");
			}
		}
		vector<string> ans;
		for(auto iter = result_set.begin();iter != result_set.end();iter++){
			ans.push_back(*iter);
		}
		return ans;
    }
    
    void findpath(set<string>& result_set,vector<vector<char>>& board,bool* flag,int x,int y,TrieNode* node,string ans){
    	if(x < 0 || y < 0 || x >= length || y >= width || flag[x*width + y]){
    		return;
		}
    	int ch = board[x][y] - 'a';
    	if(node->next[ch] != nullptr){
    		flag[x*width + y] = true;
    		node = node->next[ch];
    		ans += board[x][y];
    		if(node->end){
    			result_set.insert(ans);
			}
			findpath(result_set,board,flag,x-1,y,node,ans);
			findpath(result_set,board,flag,x+1,y,node,ans);
			findpath(result_set,board,flag,x,y-1,node,ans);
			findpath(result_set,board,flag,x,y+1,node,ans);
			flag[x*width + y] = false;
		}
		else{
			return;
		}
	}
    
    
private:
	int width,length;    	
};

