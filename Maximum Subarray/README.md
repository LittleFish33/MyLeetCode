
[原题地址](https://leetcode.com/problems/maximum-subarray/description/)

# Description

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Example:**

```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Follow up:**

If you have figured out the O(*n*) solution, try coding another solution using the divide and conquer approach, which is more subtle.

题目给了一个整数数组，求数组中连续的子数组使其和最大，返回这个最大值。

# 方法一 分治法

>  分治法（divide-and-conquer）：将原问题划分成n个规模较小而结构与原问题相似的子问题；递归地解决这些子问题，然后再合并其结果，就得到原问题的解。

根据分治法的思想，如果要求数组A[i], A[i+1], A[i+2], ... A[j]的连续子数组的最大值，将这个数组分成A[i], A[i+1], A[i+2], ... A[(i+j)/2]和A[(i+j)/2+1], A[(i+j)/2+2], A[(i+j)/2+3], ... A[j]两部分，则最大值有三种可能：

1. 最大值是左边数组A[i], A[i+1], A[i+2], ... A[(i+j)/2]的连续子数组的最大值
2. 最大值是右边数组A[(i+j)/2+1], A[(i+j)/2+2], A[(i+j)/2+3], ... A[j]的连续子数组的最大值
3. 最大值同时是数组中间位置A[(i+j)/2]向左右两边扩展得到的最大值

所以求整个数组的连续子数组的最大值就变成了求它的子数组的连续子数组的最大值。

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
        	return 0;
		}
        return getMax(nums,0,nums.size()-1);
    }
    
    // 求连续子数组的最大值 
    int getMax(vector<int>& nums, int begin, int end){
    	// 结束条件： begin == end，子数组的大小为 1 
    	if(begin == end){
    		return nums[end];
		}
		int mid = (begin + end)/2;
		// 左边的连续子数组的最大值 
		int maxLeft = getMax(nums, begin, mid);
		// 右边的连续子数组的最大值 
		int maxRight = getMax(nums, mid+1,end);
		// 跨越中间的连续子数组的最大值  
		int maxMid = getMaxMid(nums, begin, mid, end);
		// 取上面三者的最大值 
		return max(max(maxLeft, maxRight),maxMid);
	}
	
	// 求跨越中间的连续子数组的最大值  
	int getMaxMid(vector<int>& nums, int begin, int mid, int end){
		int leftMax = nums[mid],rightMax = nums[mid+1];
		int sum = 0;
		// 从中间的元素向左找以nums[mid]结尾的最大子数组 
		for(int i = mid;i >= begin;i--){
			sum += nums[i];
			if(sum > leftMax){
				leftMax = sum;
			}
		}
		sum = 0;
		// 从中间的元素向右找以nums[mid]结尾的最大子数组 
		for(int i = mid+1;i <= end;i++){
			sum	+= nums[i];
			if(sum > rightMax){
				rightMax = sum;
			}
		}
		return leftMax + rightMax;
	}
};
```

时间复杂度为O(nlogn)

# 方法二 动态规划

动态规划算法与分治法类似，其基本思想也是将待求解问题分解成若干个子问题，先求解子问题，然后从这些子问题的解得到原问题的解。与分治法不同的是，适合于用动态规划求解的问题，经分解得到子问题往往不是互相独立的。若用分治法来解这类问题，则分解得到的子问题数目太多，有些子问题被重复计算了很多次。如果我们能够保存已解决的子问题的答案，而在需要时再找出已求得的答案，这样就可以避免大量的重复计算，节省时间。我们可以用一个表来记录所有已解的子问题的答案。不管该子问题以后是否被用到，只要它被计算过，就将其结果填入表中。这就是动态规划法的基本思路。

上面的问题中，要求数组A[i], A[i+1], A[i+2], ... A[j]的连续子数组的最大值，可能有下面两种情况：

1. A[i], A[i+1], A[i+2], ... A[j-1]的连续子数组的最大值
2. A[m], A[m+1], ... A[j]的和，其中i <= m <= j

所以使用两个数组，一个数组sum，sum[i]为以A[i]结尾的子数组的最大值，一个数组Max，Max[i]为A[0], A[1], A[2], ... A[j]的子数组的最大值。

其中，sum的值很容易理解：

$$sum[i] = \begin{cases} sum[i-1]+A[i] & sum[i-1] + A[i] \ge A[i] \\ A[i] & sum[i-1] + A[i] < A[i] \end{cases}$$

那么Max[i]的值为sum[i]和Max[i-1]中的较大值

则有下面的公式：

$$Max[i] = \begin{cases} sum[i] & sum[i] \ge Max[i-1] \\ Max[i-1] &  sum[i] < Max[i-1] \end{cases}$$

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
        	return 0;
		}
		else if(nums.size() == 1){
			return nums[0];
		}
		// 保存以A[i]结尾的子数组的最大值 
		vector<int> sum(nums.size());
		// 保存A[0], A[1], A[2], ... A[j]的子数组的最大值 
		vector<int> Max(nums.size());
        sum[0] = nums[0];
        Max[0] = nums[0];
		for(int i = 1;i < nums.size();i++) {
			sum[i] = max(sum[i-1]+nums[i],nums[i]);
			Max[i] = max(sum[i],Max[i-1]);
		}
		return Max[nums.size()-1];
    }
};
```

该算法的时间复杂度为O(n)

**上面算法的优化**

可以看到，我们建了两张表，用来记录所有已解的子问题的答案。但是，我们只需要用到上一个子问题答案，因此我们只需要用一个变量来保存上一个子问题的值，即：

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
        	return 0;
		}
		else if(nums.size() == 1){
			return nums[0];
		}
        // sun保存以A[i]结尾的子数组的最大值 
        int sum = nums[0];
        // Max保存A[0], A[1], A[2], ... A[j]的子数组的最大值 
        int Max = nums[0];
		for(int i = 1;i < nums.size();i++) {
			sum = max(sum+nums[i],nums[i]);
			Max = max(sum,Max);
		}
		return Max;
    }
};
```



