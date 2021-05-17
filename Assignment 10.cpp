//============================================================================
// Name        : Assignment.cpp
// Author      : Sejal
// Version     :
// Copyright   : Your copyright notice
// Description : Implement C++ program for expression conversion as infix to postfix and
//its evaluation using stack based on given conditions: 
//1. Operands and operator, both must be single character.
//2. Input Postfix expression must be in a desired format.
//3. Only '+', '-', '*' and '/ ' operators are expected.

//============================================================================

#include <iostream>
using namespace std;
#define size 50

class Stack {
	int top;
	char stack[size];
	char infix[size];
	char postfix[size];

public:
	Stack() {
		top = -1;
	}
	void push(char x) {
		if (isfull()) {
			cout << "Stack Overflow!!!" << endl;
		} else {
			top++;
			stack[top] = x;
		}
	}

	char pop() {
		if (isempty()) {
			return ('#');
		} else {
			char s;
			s = stack[top];
			top--;
			return s;
		}
	}

	int isempty() {
		if (top == -1)
			return 1;
		else
			return 0;

	}

	int isfull() {
		if (top == size)
			return 1;
		else
			return 0;

	}

	void read() {
		cout<<"Enter an Infix Expression: ";
		cin >> infix;
	}

	int white_space(char symbol) {
		if (symbol == ' ' || symbol == '\t' || symbol == '\0')
			return 1;
		else
			return 0;
	}

	int precedence(char symbol) {
//		switch (symbol) {
//		case '/':
//			return (4);          // Precedence of / is 4
//		case '*':
//			return (3);          // Precedence of * is 3
//		case '+':
//			return (2);          // Precedence of + is 2
//		case '-':
//			return (1);          // Precedence of - is 1
//		case '(':
//			return (0);          // Precedence of ( is 0
//		default:
//			return (-1);
//		}

		 if (symbol == '+' || symbol == '-')

			return 1;

		else if (symbol == '*' || symbol == '/')

			return 2;
		else if (symbol == '(')
			return 0;

		else
			return -1;
	}

	void ConvertToPostfix() {
		int prev;
		int p = 0;
		char entry;

		for (int i = 0; infix[i] != '\0'; i++) {
			if (!white_space(infix[i])) {
				switch (infix[i]) {
				case '(':
					push(infix[i]);
					break;
				case ')':
					while ((entry = pop()) != '(')
						postfix[p++] = entry;
					break;
				case '+':
				case '-':
				case '*':
				case '/':

					if (!isempty()) {
						prev = precedence(infix[i]);
						entry = pop();
						while (prev <= precedence(entry)) {
							postfix[p++] = entry;
							if (!isempty())
								entry = pop();
							else
								break;
						}

						if (prev > precedence(entry))
							push(entry);
					}

					push(infix[i]);
					break;
				default:
					postfix[p++] = infix[i];
					break;
				}
			}
		}

		while (!isempty()){
			postfix[p++] = pop();
		}
		postfix[p] = '\0';
		cout << "The Postfix Expression is: " << postfix << endl;

	}
};

int main() {

	bool start = true;
	Stack expr;
	int choice;
	cout<<"MENU"
			"\n1.Convert Infix Expression to Postfix Expression."
			"\n0.Exit."<<endl;

	while(start){
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice){
		case 1:
			expr.read();
			expr.ConvertToPostfix();
			break;
		case 0:
			start = false;
			break;
		}

	}
	return 0;
}

//OUTPUT

/*MENU
1.Convert Infix Expression to Postfix Expression.
0.Exit.

Enter choice: 1
Enter an Infix Expression: A+B*C/(E-F)
The Postfix Expression is: ABC*EF-/+

Enter choice: 1
Enter an Infix Expression: A+B*C/D-E+F
The Postfix Expression is: ABC*D/+E-F+
*/
