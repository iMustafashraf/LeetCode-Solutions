#include<iostream>
#include<vector>
#include<queue>
#include <map>
#include <algorithm>
using namespace std;

vector<string> Addition(string cur){
    int fir = cur[0] - '0', last = cur[cur.size()-1] - '0';
    vector<string> vals;

    // Ai idea: add from last only + 0/9 trick
    if(last > 0) {
        vals.push_back(cur + to_string(last - 1));
    }
    if(last < 9) {
        vals.push_back(cur + to_string(last + 1));
    }

    return vals;
}

bool isValid(string cur, int low, int high){
    long long num = stoll(cur);

    // Check 2 rules: adjacent difference (1), in range

    for(int i = 1; i < cur.size(); ++i){
        int num1 = cur[i] - '0', num2 = cur[i-1] - '0';
        if(num1 - num2 > 1 || num1 - num2 < -1 || num1 - num2 == 0)
            return false;
    }

    if(num < low || num > high)
        return false;

    return true;
}

vector<int> bfs(int low, int high){
	map<string, bool> visited;
	vector<int> ans;
	queue<string> q;

	if(low == 0) {
		ans.push_back(0);
		visited["0"] = true;
	}

	// Stem of BFS tree (isValid will check them soon, don't worry about range!)
	for(int i = 1; i <= 9; i++){
		string num = to_string(i);
		q.push(num);
		visited[num] = true;
		if(isValid(num, low, high)){
			ans.push_back(stoi(num));
		}
	}

	while(!q.empty()){
		string cur = q.front();
		q.pop();

		vector<string> vals = Addition(cur);

		for(int i=0; i<vals.size(); i++){
			string inp = vals[i];
			if(isValid(inp, low, high) && visited[inp] != true && inp[0] != '0'){
				ans.push_back(stoi(inp));
				visited[inp] = true;
				q.push(inp);
			}
		}
	}
	sort(ans.begin(), ans.end());
	    return ans;
}

int main() {
	vector<int> vals = bfs(0, 1253);

	for(auto val : vals)
		cout << val << " ";

	return 0;
}
