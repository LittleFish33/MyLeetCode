class Solution {
public:
    string toHex(int num) {
		string ans = "";
		char ch[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
		if(num != 0){
			unsigned int value = (unsigned int )num;
			while(value > 0){
				ans = ch[value%16] + ans;
				value/=16;
			}
			return ans;
		}
		else{
			return "0";
		}
    }
};