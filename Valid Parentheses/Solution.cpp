class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(int i = 0;i < s.size();i++){
        	if(isParentheses(s[i])){
        		if(mystack.size() == 0){
        			mystack.push(s[i]);
				}
				else{
					if(isMatch(mystack.top(),s[i])){
						mystack.pop();
					}
					else{
						mystack.push(s[i]);
					}
				}
			}
		}
		return mystack.size() == 0;
    }
    
    // 判断括号是不是匹配 
    bool isMatch(char left,char right){
    	return (left == '{' && right == '}') || (left == '[' && right == ']') || (left == '(' && right == ')');
	}
	
	// 判断是不是括号 
	bool isParentheses(char ch){
		return ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == '(' || ch == ')';
	}
};