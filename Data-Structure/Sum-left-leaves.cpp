/* Notes 
    - Need information from upper nodes, not below one
    - The normal *root information isn't enough to solve it (at least for a beginner)
      - So, try to store useful values to solve the puzzle: max/min/flag...else
    - Don't pass on left nodes only; it's normal to find a left leaf node on the right of the tree!
*/

class Solution {
public:
    int sumleft(TreeNode* root, bool isleft = false){
       if(!root)
        return 0;

         if(root->left == nullptr && root->right == nullptr && isleft)
            return root->val;

        int l = sumleft(root->left, true);
        int r = sumleft(root->right, false);
        return l + r;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sumleft(root);
    }
};
