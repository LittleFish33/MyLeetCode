# 451. Sort Characters By Frequency

题目：[Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/)

总结：

这里保存了一个之前不知道的用法：

```
vector<pair<int,char> > a(128);
// 此时会根据int的值排序
sort(a.begin(),a.end());
```

