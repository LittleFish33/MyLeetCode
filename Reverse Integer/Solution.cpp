class Solution {
public:
    int reverse(int x) {
        int max_number = 0,ans = 0,remain = 0,value = 0;
        
        while(x != 0){
        	remain = x%10;
			x/=10;
			max_number++;
			/*
			第一种解法：根据 2^31 的值进行判断是否越界 
			if(max_number == 10){
				if(ans > 214748364 ||  (remain >= 8 && x > 0) || ans < -214748364 || (remain <= -7 && x < 0))
				return 0;
			}
			ans = ans * 10 + remain;
			*/
			
			/*
			* 第二种解法 ： 从讨论上看到的，通过还原进位的值判断是否和原来的值相同判断是否越界 
			*/ 
			value = ans * 10 + remain;
			if((value - remain)/10 != ans){
				return 0;
			}
			else{
				ans = value;
			}
		}
		return ans;
    }
};

