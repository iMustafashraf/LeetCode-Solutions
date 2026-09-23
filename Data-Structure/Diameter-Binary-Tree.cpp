/* Notes:
    - The long node mustn't be the root; it may be any node in the tree.
    - I tested myself with the left and right paths, trying to reach the root of maximum diameter
    - For each node: 1- calc the depth of left/right   2- combine (l + r)    3- raise the result to parent
*/

class Solution {
public:
    int maxDepth(TreeNode *root) { // O(n) time / memory
        if (!root)
            return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) { // O(n^2) time / memory
        if(!root) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int di = left + right;

        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);

        int pre = max(l, r);
        return max(di, pre);
    }
};
