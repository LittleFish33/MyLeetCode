# Roman to Integer

题目：[Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/)

总结：

一位一位处理字符串，需要判断下一位是什么才能判断这一位的意义

Solution1是自己一开始写的，弱弱地写了一堆`if-else`判断

Solution2是看讨论写的，实际上只需要判断下一位是不是大于上一位就可以了，再使用`unordered_map`就可以很简单的判断了

```c++
unordered_map<char,int> dict = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
int ans = 0;
for(int i = 0;i < s.size()-1;i++){
    if(dict[s[i]] < dict[s[i+1]]){
        ans -= dict[s[i]];
    }
    else{
        ans += dict[s[i]];
    }
}
ans += dict[s.back()];
```

