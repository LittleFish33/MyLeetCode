# Word Search II
题目：[Word Search II](https://leetcode.com/problems/word-search-ii/)

总结：

类似骑士游历问题的搜索过程，难的地方在于超时问题，这里使用了字典树进行查询，此时搜索过程中字符串组中存在相同的前缀的时候这些前缀可以避免重复搜索。