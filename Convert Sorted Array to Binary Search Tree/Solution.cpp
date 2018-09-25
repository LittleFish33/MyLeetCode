class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createTree(nums,0,nums.size()-1);
    }
    
	TreeNode* createTree(vector<int>& nums,int left,int right){
		if(left > right){
			return nullptr;
		}
		else{
			TreeNode* leftNode = createTree(nums,left,(left+right)/2-1);
			TreeNode* rightNode = createTree(nums,(left+right)/2+1,right);
			TreeNode* node = new TreeNode(nums[(left+right)/2]);
			node->left = leftNode;
			node->right = rightNode;
			return node;
		}
	}
    
};