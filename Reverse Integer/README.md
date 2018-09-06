# Reverse Integer
题目：[Reverse Integer](https://leetcode.com/problems/reverse-integer/)

总结：把一个数字反转，比较麻烦的是需要判断是否超过`int`的表示范围

一开始是通过比较$2^{31}$次方的值来进行解决的：

```c++
if(max_number == 10){
    if(ans > 214748364 ||  (remain >= 8 && x > 0) || ans < -214748364 || (remain <= -7 && x < 0))
        return 0;
}
```

后面使用还原的方法：

```c++
value = ans * 10 + remain;
if((value - remain)/10 != ans){
    return 0;
}
else{
    ans = value;
}
```

