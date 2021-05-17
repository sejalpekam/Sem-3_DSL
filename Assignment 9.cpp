//============================================================================
// Name        : Assignment.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : In any language program mostly syntax error occurs due to
//unbalancing delimiter such as { }, [ ] and ( ).
//Write C++ program using stack to check whether given expression is well parenthesized or not.
//============================================================================

#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
#define size 10

class Stack {
	int top;
	char stack[size];
public:
	Stack() {
		top = -1;
	}

	int isempty() {
		if (top == -1)
			return 1;
		else
			return 0;

	}

	int isfull() {
		if (top == size-1)
			return 1;
		else
			return 0;

	}

	void push(char x) {
		if(isfull()){
			cout<<"Stack Overflow!"<<endl;
			return;
		}

		top++;
		stack[top] = x;
	}

	char pop() {
		if(isempty()){
			return -1;
		}

		char s;
		s = stack[top];
		top--;
		return s;
	}

	char topelement(){
		return stack[top];
	}

};

class expression {
	char exp[100];
	Stack *sp = new Stack();

public:
	void input() {
		cout << "Enter the expression : ";
		cin >> exp;
	}
	bool check() {
		for (int i = 0; i <= (int)sizeof(exp); i++) {
			if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
				sp->push(exp[i]);
				continue;
			}
			char x;
			switch (exp[i]) {
			case ')':
				x = sp->topelement();
				sp->pop();
				if (x == '[' || x == '{') {
					return false;
				}
				break;

			case '}':
				x = sp->topelement();
				sp->pop();
				if (x == '[' || x == '(') {
					return false;
				}
				break;
			case ']':
				x = sp->topelement();
				sp->pop();
				if (x == '(' || x == '{') {
					return false;
				}
				break;

			default:
				break;
			}
		}

		if (sp->isempty()) {
			return true;
		} else {
			return false;
		}
	}
};

int main() {

	int option;
	bool start = true;

	while (start) {
		cout<< "---------------------------------------MENU-------------------------------------"
						"\n1. Check expression."
						"\n0. Exit." << endl;
		cout << "\nEnter choice: ";
		cin >> option;
		cin.ignore();

		switch (option) {
		case 1:
		{
			expression expr;
			expr.input();

			if (expr.check()) {
				cout << "Expression is well parenthesized." << endl;
			} else {
				cout << "Invalid Expression or not well parenthesized." << endl;
			}
			break;
		}

		case 0:
			start = false;
			break;

		}

	}


	return 0;
}

