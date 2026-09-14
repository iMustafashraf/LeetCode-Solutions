/* Take care !
  1- Code will get bigger than this if it's not planned well => write 4 cases & results before coding
  2- Line number (), if we don't write else if => after deletion we may go empty, so add the same number! [8, -8]
  3- Some of us may think in reverse direction => (+) attack [-, +, -], Stack is from left not from right 
    - the right direction is [-, +, -] + then (+) go right --> and (-) go left <--
  4- Don't forget to add stack to vector in reversed direction, LIFO systematic
*/

vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> bomp;

        for(auto num : asteroids){

            if(bomp.empty() || !( bomp.top() > 0 && num < 0)) {
                bomp.push(num);
            }else{
                while(!bomp.empty() &&  bomp.top() > 0 &&  bomp.top() < -num) {
                    bomp.pop();
                    if(!bomp.empty())  bomp.top() = bomp.top();
                }

                // Reverse of while(..conditions..)
                if(!bomp.empty() &&  bomp.top() > 0 &&  bomp.top() == -num) {
                    bomp.pop();
                } 
                else if(bomp.empty() ||  bomp.top() < 0) { 
                    bomp.push(num); 
                }
            }
        }

        const int val = bomp.size();
        vector<int> ans(val);
        for(int i = bomp.size() - 1; i >= 0; i--){
            ans[i] = bomp.top();
            bomp.pop();
        }
        
        return ans;
    }
