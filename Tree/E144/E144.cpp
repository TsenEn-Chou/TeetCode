#include <iostream>
#include <vector>
using namespace std;
vector<int> sol;

struct TreeNode {
    int val;
   	TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> preorderTraversal(TreeNode* root) {		
	if(root){
		preorderTraversal(root->left);
		sol.push_back(root->val);
		preorderTraversal(root->right);
	}
	return sol;
}
int main(int argc,char **argv){
	TreeNode root;
	root.val = 10;
	TreeNode RL(20);
	TreeNode RR(30);
	root.left = NULL;
	root.right = &RR;
	preorderTraversal(&root);
	for(auto y : sol)
		cout << y;
	cout <<endl;
	return 0;
}