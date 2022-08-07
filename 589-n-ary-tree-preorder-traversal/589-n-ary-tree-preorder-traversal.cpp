class Solution {
public:
	void f(Node* curr,vector<int>& ans){
		if(!curr) return;
		ans.push_back(curr->val);
		for(int i=0;i<curr->children.size();i++) f(curr->children[i],ans);
	}

	vector<int> preorder(Node* root) {
		vector<int>ans;
		if(!root)return ans;
		f(root,ans);
		return ans;
	}
};