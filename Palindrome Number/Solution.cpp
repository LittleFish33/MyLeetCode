class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
        	return false;
		}
		int arr[10];
		int j = 0;
		while(x > 0){
			arr[j++] = x%10;
			x/=10;
		}
		int temp = j-1;
		for(int i = 0;i < j/2;i++){
			if(arr[i] != arr[temp--]){
				return false;
			}
		}
		return true;
    }
};
