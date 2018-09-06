#include <iostream>
#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <unordered_map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size() == 0){
    		return "";
		}
        int j = 0;
        char c;
		string ans = "";
        while(true){
        	c = strs[0][j];
        	if(c == '\0'){
        		return ans;
			}
        	for(int i = 1;i < strs.size();i++){
        		if(strs[i][j] != c || strs[i][j] == '\0'){
        			return ans;
				}
			}
			ans+=c;
			j++;
		}
    }
};
    
int main()
{
	Solution solution;
	string arr[3] = {"flower","flow","flight"};
	vector<string> strs(arr,arr+3);
	cout << solution.longestCommonPrefix(strs) << endl;	
} 

