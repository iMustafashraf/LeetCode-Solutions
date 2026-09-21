/* Take care
  - Don't make them 2 returns: 
    1- The upper return would be executed, but the lower one won't.
    2- According to (1), you will search in the left/right side nodes only.
  - Right approach
    Search all directions in the tree, trying to find the maximum number.
    You can also simplify it by putting values in variables first.
*/

class Solution{
public:
	int MaxDepth(TreeNode *root){
		if(!root) return 0;

		return 1 + max(MaxDepth(root->right), MaxDepth(root->left));
	}
};

int main() {
	BinaryTree tree(1);
	cout << Solution().MaxDepth(tree.root) << "\n";

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	cout << Solution().MaxDepth(tree.root) << "\n";

	tree.add( { 2, 4, 8 , 2, 7}, { 'L', 'L', 'R', 'L', 'L' });
	cout << Solution().MaxDepth(tree.root) << "\n";

	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	cout << Solution().MaxDepth(tree.root) << "\n";

	tree.add( { 2, 4, 8 , 2, 7, 10, 20, 30}, { 'L', 'L', 'R', 'L', 'L' , 'R', 'R', 'R'});
	cout << Solution().MaxDepth(tree.root) << "\n";

	tree.print_inorder();
	// 7 4 8 2 5 9 1 3 10 6

	return 0;
}

/* Output
  1
  4
  6
  6
  9
  7 4 8 2 5 9 1 3 10 6
*/
