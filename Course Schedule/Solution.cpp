class Graph{
private:
	int nums;
	std::vector<int>* adj;
	vector<int> indegree;
public:
	Graph(int v){
		nums = v;
		adj = new std::vector<int>[nums]; 
		for (int i = 0; i < v; ++i)
		{
			indegree.push_back(0);
		}
	}

	~Graph(){
		delete []adj;
	}

	void addEdge(int from,int to){
		adj[from].push_back(to);
		indegree[to]++;
	}
	
	
	bool topological_sort(){
		queue<int> q;
		
		for(int i = 0;i < nums;i++){
			if(indegree[i] == 0){
				indegree[i] = -1;
				q.push(i);
			}
		}
		
		int count = 0,temp;
		while(!q.empty()){
			temp = q.front();
			q.pop();
			count++;
			for(auto value:adj[temp]){
				indegree[value]--;
			}
			for(int i = 0;i < nums;i++){
				if(indegree[i] == 0){
					indegree[i] = -1;
					q.push(i);
				}
			}
		}
		return (count == nums);
	}
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph graph(numCourses);
        for(auto value:prerequisites){
			graph.addEdge(value.first,value.second);
		}
		return graph.topological_sort();
    }
};
