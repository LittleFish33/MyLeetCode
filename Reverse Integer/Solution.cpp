class Solution {
public:
    int reverse(int x) {
        int max_number = 0,ans = 0,remain = 0,value = 0;
        
        while(x != 0){
        	remain = x%10;
			x/=10;
			max_number++;
			/*
			��һ�ֽⷨ������ 2^31 ��ֵ�����ж��Ƿ�Խ�� 
			if(max_number == 10){
				if(ans > 214748364 ||  (remain >= 8 && x > 0) || ans < -214748364 || (remain <= -7 && x < 0))
				return 0;
			}
			ans = ans * 10 + remain;
			*/
			
			/*
			* �ڶ��ֽⷨ �� �������Ͽ����ģ�ͨ����ԭ��λ��ֵ�ж��Ƿ��ԭ����ֵ��ͬ�ж��Ƿ�Խ�� 
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

