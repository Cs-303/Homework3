#pragma once
#include <iostream>
#include "Stack.h"
using namespace std;


//class for Infix conversion
class InFix_To_PostFix {
private:
	Stack<char> exStack;
	string open = "([{";
	string close = ")]}";

public:
	//give value to certain operators (from order in highest to lowest depending on PEMDAS)
	int precedence(char value) {
		switch (value) {
		case '^':
			return 3;
		case '*':
		case '%':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		}
	}

	//return true or false if parenthesis in the expression is balanced.
	bool isBalanced(string input) {
		bool balanced = true;
		while (!exStack.empty()) exStack.pop();   //reset everything

		string::iterator iter = input.begin();
		while (balanced && (iter != input.end())) {
			if (open.find(*iter) != string::npos) exStack.push(*iter);
			else if (close.find(*iter) != string::npos) {
				if (exStack.empty()) balanced = false;
				else {
					balanced = (open.find(exStack.top()) == close.find(*iter));
					exStack.pop();
				}
			}
			iter++;
			if (!exStack.empty() && (iter == input.end())) balanced = false;
		}
		return balanced;
	}

	//automatically covnert infix expression to postfix
	void convert(string input) {
		string postfix = "";

		for (int i = 0; i < input.size(); i++) {
			switch (input[i]) {
			case ' ':
				break;

			case '(': case '[': case '{':
				exStack.push(input[i]);
				break;


			case ')': case ']': case '}':
				while (open.find(exStack.top()) == string::npos) {
					postfix += exStack.top();
					exStack.pop();
				}
				exStack.pop();
				break;


			case '^': case '*': case '%': case '/': case '+': case '-':
				while (!exStack.empty()
					&& (open.find(exStack.top()) == string::npos)
					&& (precedence(input[i]) <= precedence(exStack.top()))) {
					postfix += exStack.top();
					exStack.pop();
				}
				exStack.push(input[i]);
				break;


			default:
				postfix += input[i];
			}

		}
		while (!exStack.empty()) {
			postfix += exStack.top();
			exStack.pop();
		}


		cout << "Postfix form: " << postfix << endl;
		//exStack.show_list();


	}


};
