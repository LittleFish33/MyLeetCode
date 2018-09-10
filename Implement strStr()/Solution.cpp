class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle.size() == 0){
    		return 0;
		}
    	int* next = new int[needle.size()];
        getNext(needle,next);
        int ans = KMP(haystack, needle, next);
        delete []next;
        return ans;
    }
    
    void getNext(string needle,int* next){
    	next[0] = -1;
    	int j = 0,k = -1;
    	while(j < needle.size()-1){
    		if(k == -1 || needle[j] == needle[k]){
    			if(needle[++j] == needle[++k]){
    				next[j] = next[k];
				}
				else{
					next[j] = k;
				}
			}
			else{
				k = next[k];
			}
		}
	}
	
	int KMP(string haystack,string needle,int* next){
		int i = 0,j = 0;
		while(i != haystack.size() && j != needle.size()){
			if(j == -1 || haystack[i] == needle[j]){
				i++;
				j++;
			}
			else{
				j = next[j];
			}
		}
		if(j == needle.size()){
			return i-j;
		}
		else{
			return -1;
		}
	}
};