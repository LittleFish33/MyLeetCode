class Solution {
public:
    string countAndSay(int n) {
		string str = "1",temp;
		char value;
		int count;
		for(int i = 2;i <= n;i++){
			temp = "";
			count = 0;
			value = str[0];
			for(int j = 0;j < str.size();j++){
				if(str[j] == value){
					count++;
				}
				else{
					temp += (count + '0');
					temp += value;				
					value = str[j];
					count = 1;
				}
			}
			temp += (count + '0');
			temp += value;
			str = temp;
		}
		return str;
    }
};