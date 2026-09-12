bool brackets(string str){
	
	stack<char> stk;
	for(auto s : str){
		if(s == '(' || s == '[' || s == '{'){
			stk.push(s);
		}else{
			if(stk.empty()) return false; // Nothing to respond on ), ], }
			
			char top = stk.top();
			if ((s == ')' && top == '(') ||
				(s == ']' && top == '[') ||
				(s == '}' && top == '{'))
				stk.pop();
			else return false;
		}
	}
	
	return stk.empty(); // if stack still have one of (, [, {
	
}
