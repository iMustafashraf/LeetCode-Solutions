// I know, it can be more concise if we only sort the main 2D vector

class Solution {
public:
    vector<vector<int>> build(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            res.push_back({intervals[i][0], i});
        }

        sort(res.begin(), res.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

        return res;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        vector<int> res;
        vector<vector<int> > forloop = build(intervals);
        for(int i=0; i<intervals.size(); i++){

            int st = 0, end = forloop.size()-1, ans = -1;
            while(st <= end){
                int mid = st + (end - st) / 2;

                if(intervals[i][1] > forloop[mid][0]){
                    st = mid + 1;
                }else {
                   end = mid - 1, ans = forloop[mid][1];
                }
            }

            // if(st > forloop.size() - 1 || st < 0)
            //     res.push_back(-1);
            // else 
                res.push_back(ans); 
        }
        return res;
    }
};
