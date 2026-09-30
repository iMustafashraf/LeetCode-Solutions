class Solution {
public:
    bool compare(TreeNode* turnLeft, TreeNode* turnRight){
        if(!turnLeft && !turnRight) return true;
        if(!turnLeft || !turnRight) return false;

        if(turnLeft->val != turnRight->val) return false;

        return compare(turnLeft->left, turnRight->right) && compare(turnLeft->right, turnRight->left);
    }

    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};
