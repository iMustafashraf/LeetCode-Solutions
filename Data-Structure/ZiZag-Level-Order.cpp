/* Note
    - ChatGPT helped me with : 
      1. Adding to the vector must be first; then do your deque operation.
      2. Use a 1D Vector to add 1 line, then add all of it to a 2D vector
        - Find the Depth of the tree => Create a sized 2D vector.
        - Enter an empty array into a 2D Vector => insert in the last row using .back().
      3. Spimplify even = !even. (I have written 2 lines for that!)
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > ans;
        if(!root) return ans;

        deque<TreeNode*> QueueTree, temp;
        QueueTree.push_back(root);

        bool even = false;
        int level = 0, i = 0;

        while(!QueueTree.empty()){

            int sz = QueueTree.size(); 
            vector<int> currentlevel(sz);

            level++;
            i = 0;

            temp = QueueTree;

            while(!temp.empty()){
                if(!even){
                    auto node = temp.front();
                    temp.pop_front();
                    currentlevel[i] = node->val;
                    i++;
                }else{
                    auto node = temp.back();
                    temp.pop_back();
                    currentlevel[i] = node->val;
                    i++;
                }
            }

            ans.push_back(currentlevel);

            while(sz--){
                TreeNode* curr = QueueTree.front();
                QueueTree.pop_front();

                if(curr->left)
                    QueueTree.push_back(curr->left);
                if(curr->right)
                    QueueTree.push_back(curr->right);
            }

            even = !even;

        }
        return ans;
    }
};
