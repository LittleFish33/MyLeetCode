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
#include <cstring>
#include <ctime>
#include <cmath>
using namespace std;
/* 解法一：运行前请先注释掉解法二 */
/*
 * Description: 节点
 * @param: num 节点的值
 * @adj: 节点的所有邻居 
 */ 
struct Node{
	int num;
	vector<Node*> adj;
	Node(int n) {
		num = n;
	}
};

class Solution {
private:
	// 保存计算过的高度 
	map<pair<int,int>,int> height_table;
	
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    	// 答案 
        vector<int> ans;
        // 所有节点 
		vector<Node*> nodes;
		
		// 构造图 
		for (int i = 0; i < n; ++i)
		{
			Node* node = new Node(i);
			nodes.push_back(node);
		}
		for(auto& value : edges){
			nodes[value.first]->adj.push_back(nodes[value.second]);
			nodes[value.second]->adj.push_back(nodes[value.first]);
		}

		int height[n];
		int minh = INT_MAX;
		
		// 遍历所有的节点，以该节点为根节点计算高度 
		for (int i = 0; i < n; ++i)
		{
			height[i] = getHeight(nodes[i], NULL);
			minh = min(minh, height[i]);
		}

		// 高度 == 最小高度，将该节点添加到输出向量 
		for (int i = 0; i < n; ++i)
		{
			if(height[i] == minh){
				ans.push_back(i);
			}
		}
		return ans;

    }


	// 获取以parent为父节点的节点node的高度 
    int getHeight(Node* node,Node* parent){
    	int h = 0,temp;
    	for (int i = 0; i < node->adj.size(); ++i)
    	{
    		Node* neighbor = node->adj[i];
    		if(neighbor == parent){
    			continue;
			}
			// 表中没有记录，则递归调用 
    		if(height_table.find({node->num,neighbor->num}) == height_table.end()){
    			temp = getHeight(neighbor, node);
    			height_table.insert({{node->num,neighbor->num},temp});
    		}
    		// 表中有记录，直接取表中的值 
    		else{
    			temp = height_table[{node->num,neighbor->num}];
    		}
    		h = max(h,temp);
    	}
    	return h + 1;
    }
};


/* 解法二：运行前请先注释掉解法一 */
/*
 * Description: 节点
 * @param: num 节点的值
 * @adj: 节点的所有邻居 
 */ 
struct Node{
	int num;
	unordered_set<Node*> adj;
	Node(int n) {
		num = n;
	}
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		// 构造图 
		map<int,Node*> nodes;
		for (int i = 0; i < n; ++i)
		{
			Node* temp = new Node(i);
			nodes.insert({i,temp});
		}

		for (auto value : edges)
		{
			nodes[value.first]->adj.insert(nodes[value.second]);
			nodes[value.second]->adj.insert(nodes[value.first]);
		}

		while(nodes.size() > 2){
			vector<Node*> leftNodes;
			// 找到所有叶节点 
			for(auto value : nodes){
				if(value.second->adj.size() == 1){
					leftNodes.push_back(value.second);
				}
			}

			// 遍历叶节点，从它们的邻居中删除边，最后在从图中删除叶节点 
			for(auto left : leftNodes){
				for(auto value : left->adj){
					nodes[value->num]->adj.erase(left);
				}
				nodes.erase(left->num);
			}
		}
		
		// 图中剩下的节点就是最小树的叶节点，输出这些节点 
		std::vector<int> ans;
		for(auto value : nodes){
			ans.push_back(value.first);
		}
		return ans;
    }
};



int main()
{
	int n = 6;
	vector<pair<int, int>> edges;
	edges.push_back({3,0});
	edges.push_back({3,1});
	edges.push_back({3,2});
	edges.push_back({3,4});
	edges.push_back({5,4});
	Solution solution;
	vector<int> ans = solution.findMinHeightTrees(n,edges);
	for(auto value : ans){
		cout << value << endl;
	}
	return 0;
}




