class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr){
        	return nullptr;
		}
		else{
			UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
			m.insert({res->label,res});
			cloneNode(res,node);
			return res;
		}
    }
    
    
    void cloneNode(UndirectedGraphNode *res,UndirectedGraphNode *node) {
    	for(auto value : node->neighbors){
			if(m.find(value->label) == m.end()){
				UndirectedGraphNode * temp = new UndirectedGraphNode(value->label);
				res->neighbors.push_back(temp);
				m.insert({temp->label,temp});
				cloneNode(temp,value);
			}
			else{
				res->neighbors.push_back(m[value->label]);
			}
		} 
	}
	
	
	map<int, UndirectedGraphNode *> m;
};
