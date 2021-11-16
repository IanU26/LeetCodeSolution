//Balanced Parentheses solved with STACK

#include <iostream>

using namespace std;

struct Node {
	char data;
	Node* link;
};

class Stack {
private:
	Node* top1 = NULL;			
public:
	void push(char x) {
		Node* temp = new Node();	
		temp->data = x;				
		temp->link = top1;			
		top1 = temp;				
	}
	void pop() {
		if (top1 == NULL) {
			cout << "No value to pop \n";
		}
		else {
			Node* temp = top1;
			temp = temp->link;			
			top1 = temp;				
		}
	}
	char top() {
		if (top1 == NULL) {
			cout << "Stack is empty. \n";
		}
		else {
			return top1->data;
		}
	}
	bool isEmpty() {
		if (top1 == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
};


bool balanced(string s, Stack s1) {
	int n = s.length();
	for (int i = 0; i < n; i++) {

		//If there is an open parentheses, push it to stack.
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {			
			s1.push(s[i]);
		}
		//If there is a closed parentheses and the stack is empty the expression is invalid. 
		else if ((s[i] == '}' || s[i] == ']' || s[i] == ')') && s1.isEmpty() == true) {			 
			return false;																		
		}
		//If there is a closed parentheses, check the stack for most recent open parentheses. If it matches, pop the stack. 
		else if ( (s[i] == '}' && s1.top() == '{') || (s[i] == ']' && s1.top() == '[') || (s[i] == ')' && s1.top() == '(')) {
			s1.pop();
		}
		//If there is a closed parentheses and it doesnt match, return false
		else if ((s[i] == '}' && s1.top() != '{') || (s[i] == ']' && s1.top() != '[') || (s[i] == ')' && s1.top() != '(')) {
			return false;
		}
	
	}
	return s1.isEmpty();		//If the stack is empty then the parentheses must have been balanced. If there is still objects in the stack
								//the parentheses could not have been balanced. This is because any balanced parentheses would've been pop().

}

int main() {
	Stack s1;
	string s = "[({A+B}{C+D})]";
	cout <<"Checking if the expression \'[({A+B}{C+D})]\' has balanced parentheses: " << balanced(s, s1) << "\n";
	Stack s2;
	string ss = "[}{}";
	cout << "Checking if the expression \'[}{}\' has balanced parentheses: " << balanced(ss, s2) <<"\n";
	Stack s3;
	string sss = "[]{}(";
	cout << "Checking if the expression \'[]{}(\' has balanced parentheses: " << balanced(sss, s3) << "\n";
}
