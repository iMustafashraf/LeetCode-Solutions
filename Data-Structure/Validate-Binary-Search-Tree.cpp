/*
         5
       /   \
      3      6
     / \    / \
    2   4  3   8

  - You need max/min to be sure that 3 is not less than 5 (this is not a Binary Search Tree!)
  - Using normal comparison operators is not effective (compare 5 with 6 => right, compare 6 with 3 => right)
*/

/* Wrong Approach

    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if (!root) return true;   
    
            auto l = root->val > isValidBST(root->left);
            auto r = root->val < isValidBST(root->right);
            return l && r;
        }
    };
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

    bool validate(TreeNode* node, long long min_val, long long max_val) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        return validate(node->left, min_val, node->val) && 
               validate(node->right, node->val, max_val);
    }
};

