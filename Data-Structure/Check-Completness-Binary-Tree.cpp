/* Idea
    - Find the real number of nodes in a tree.
    - Compare the level-order traversal using a queue with that number upside..
    - Still contain some nodes? It's not complete.
*/

class Solution {
public:
    int count(TreeNode* root){ // O(n) time / memory
        if (root == nullptr)  return 0;
    
        return 1 + count(root->right) + count(root->left);
    }

    bool isCompleteTree(TreeNode* root) { // O(n) time / memory
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        int sz = 1, cnt = 0, TreeNodes = count(root); // Occured one time!
        bool cut = false;
        TreeNodes -= 1;

        while(!nodeQueue.empty()){
           
           sz = nodeQueue.size();
           if(cut) break;

            while(sz--){
                 TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();
                

                if(curr->left){
                    nodeQueue.push(curr->left);
                    cnt++;
                }else {
                    cut = true;
                    break;
                }

                if(curr->right){
                    nodeQueue.push(curr->right);
                    cnt++;
                }else {
                    cut = true;
                    break;
                }
            }
        }

        TreeNodes -= cnt;
        return TreeNodes == 0;
    }
};
