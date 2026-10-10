// You feel like it's very hard!! But after some analysis => easyyyyyy
// Simply: reverse the arrows!

 void sol (TreeNode* root){
        if(!root)
            return;

        TreeNode* leftt = root->left;
        root->left = root->right;
        root->right = leftt;

        sol(root->left);
        sol(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        sol(root);
        return root;
    }
