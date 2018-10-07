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
/* �ⷨһ������ǰ����ע�͵��ⷨ�� */
/*
 * Description: �ڵ�
 * @param: num �ڵ��ֵ
 * @adj: �ڵ�������ھ� 
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
	// ���������ĸ߶� 
	map<pair<int,int>,int> height_table;
	
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    	// �� 
        vector<int> ans;
        // ���нڵ� 
		vector<Node*> nodes;
		
		// ����ͼ 
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
		
		// �������еĽڵ㣬�Ըýڵ�Ϊ���ڵ����߶� 
		for (int i = 0; i < n; ++i)
		{
			height[i] = getHeight(nodes[i], NULL);
			minh = min(minh, height[i]);
		}

		// �߶� == ��С�߶ȣ����ýڵ���ӵ�������� 
		for (int i = 0; i < n; ++i)
		{
			if(height[i] == minh){
				ans.push_back(i);
			}
		}
		return ans;

    }


	// ��ȡ��parentΪ���ڵ�Ľڵ�node�ĸ߶� 
    int getHeight(Node* node,Node* parent){
    	int h = 0,temp;
    	for (int i = 0; i < node->adj.size(); ++i)
    	{
    		Node* neighbor = node->adj[i];
    		if(neighbor == parent){
    			continue;
			}
			// ����û�м�¼����ݹ���� 
    		if(height_table.find({node->num,neighbor->num}) == height_table.end()){
    			temp = getHeight(neighbor, node);
    			height_table.insert({{node->num,neighbor->num},temp});
    		}
    		// �����м�¼��ֱ��ȡ���е�ֵ 
    		else{
    			temp = height_table[{node->num,neighbor->num}];
    		}
    		h = max(h,temp);
    	}
    	return h + 1;
    }
};


/* �ⷨ��������ǰ����ע�͵��ⷨһ */
/*
 * Description: �ڵ�
 * @param: num �ڵ��ֵ
 * @adj: �ڵ�������ھ� 
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
		// ����ͼ 
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
			// �ҵ�����Ҷ�ڵ� 
			for(auto value : nodes){
				if(value.second->adj.size() == 1){
					leftNodes.push_back(value.second);
				}
			}

			// ����Ҷ�ڵ㣬�����ǵ��ھ���ɾ���ߣ�����ڴ�ͼ��ɾ��Ҷ�ڵ� 
			for(auto left : leftNodes){
				for(auto value : left->adj){
					nodes[value->num]->adj.erase(left);
				}
				nodes.erase(left->num);
			}
		}
		
		// ͼ��ʣ�µĽڵ������С����Ҷ�ڵ㣬�����Щ�ڵ� 
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




