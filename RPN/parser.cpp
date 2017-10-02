#include "parser.hpp"
#include <stack>

namespace CYA{
	bool lessPrec(const char a, const char b){
		std::string op = "|^+*";
		int aValue, bValue;
		for(int i=0; i<op.size(); i++){
			if(a == op[i])
				aValue = i;
			if(b == op[i])
				bValue = i;
		}

		return aValue <= bValue;
	}

	bool isOp(const char a){
		if(a == '|' || a == '^' || a == '+' || a == '*' || a == '(' || a == ')')
			return true;
		else
			return false;
	}

	std::string inf2Pos(std::string er){
		std::stack<char> tokenStack;
		std::string erRPN;
		for(int i = 0; i < er.size(); i++)
			if(isOp(er[i])){
				switch(er[i]){
					case '(': 
						while(!tokenStack.empty() && '(' == tokenStack.top()){
							if(tokenStack.top() != '(')
								erRPN.push_back(tokenStack.top());
							tokenStack.pop();
						}
						tokenStack.push('(');
					break;
					case ')':
						while(!tokenStack.empty() && tokenStack.top() != '('){
							if(tokenStack.top() != '(')
								erRPN.push_back(tokenStack.top());
							tokenStack.pop();
						}
					break;
					default:	// "|, ^, +, *"
						while(!tokenStack.empty() && lessPrec(er[i], tokenStack.top())){
							if(tokenStack.top() != '(')
								erRPN.push_back(tokenStack.top());
							tokenStack.pop();
						}
						tokenStack.push(er[i]);
				}
			}
			else
				erRPN.push_back(er[i]);
				
		while(!tokenStack.empty()){
			if(tokenStack.top() != '(')
				erRPN.push_back(tokenStack.top());
			tokenStack.pop();
		}

		return erRPN;
	}
}