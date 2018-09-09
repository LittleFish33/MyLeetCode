class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1 == nullptr){
        	return l2;
		}
		if(l2 == nullptr){
			return l1;
		}
        ListNode* node1 = l1,*node2 = l2; 
        ListNode* ans = new ListNode(0),*temp = ans;
        
        while(node1 != nullptr && node2 != nullptr){
        	if(node1->val <= node2->val){
	        	temp->next = new ListNode(node1->val);
	        	temp = temp->next;
	        	node1 = node1->next;
			}
			else{
				temp->next = new ListNode(node2->val);
	        	temp = temp->next;
				node2 = node2->next;
			}
		}
		
		while(node1 != nullptr){
			temp->next = new ListNode(node1->val);
	    	temp = temp->next;
	    	node1 = node1->next;
		}
		
		while(node2 != nullptr){
			temp->next = new ListNode(node2->val);
	    	temp = temp->next;
	    	node2 = node2->next;
		}
		
		temp = ans;
		ans = ans->next;
		delete temp;
		return ans;
    }
};
