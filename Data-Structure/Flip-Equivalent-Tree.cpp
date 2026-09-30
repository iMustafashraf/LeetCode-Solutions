class Solution {
public:

    string parenthesize_can(TreeNode* root){
        if(!root)
            return "()";

        string repr = "(" + to_string(root->val);

        vector<string> can;

        if(root->left)
            can.push_back(parenthesize_can(root->left));
        else
            can.push_back("()");

        if(root->right)
            can.push_back(parenthesize_can(root->right));
        else
            can.push_back("()");

        sort(can.begin(), can.end());
        for(int i=0; i<can.size(); i++){
            repr += can[i];
        }
        repr += ")";
        return repr;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return parenthesize_can(root1) == parenthesize_can(root2);
    }
};
