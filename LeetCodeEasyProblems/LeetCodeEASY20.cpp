//Leetcode 20: Valid Parentheses

//Problem:Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
	//An input string is valid if:
	//1. Open brackets must be closed by the same type of brackets.
	//2. Open brackets must be closed in the correct order.
	//Example: '[][][]' is valid. '[[[]]]' is also valid. '{}[[()' is NOT valid.

//Thought process: 
	//If the string has an odd number of characters it can not be valid so immediately check and return false if odd.
	//Starting at the center of the string compare the inner most characters to see if they are a complete (open&close) bracket. If 
	//they make a complete bracket erase them and continue. 
	//If all characters are erased in this process return true.
	//If there is ever not a match at the center move the next process.
	//Taking the remaining string, starting at the beginning compare the first two characters. If they make a complete bracket erase them. 
	//Once again if all characters are erased in this process return true. If there is ever not a match then the input string is not valid and 
	//false is returned. 

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:

	bool isValid(string s) {

		int i = 0;
		if (s.length() % 2 != 0) {
			return false;
		}
		while (i == 0) {
			int length = s.length();

			if (length == 0) {
				return true;
			}
			else if (s[length / 2 - 1] == '(' && s[length / 2] == ')') {
				s.erase(length / 2 - 1, 2);
			}
			else if (s[length / 2 - 1] == '{' && s[length / 2] == '}') {
				s.erase(length / 2 - 1, 2);
			}
			else if (s[length / 2 - 1] == '[' && s[length / 2] == ']') {
				s.erase(length / 2 - 1, 2);
			}
			else {
				i += 1;
			}
		}

		int secondlength = s.length();

		while (i == 1) {
			if (s.length() == 0) {
				return true;
			}
			else if (s[0] == '(' && s[1] == ')') {
				s.erase(0, 2);
			}
			else if (s[0] == '{' && s[1] == '}') {
				s.erase(0, 2);
			}
			else if (s[0] == '[' && s[1] == ']') {
				s.erase(0, 2);
			}
			else {
				return false;
			}

		}
	}
};

//Examples
int main() {
	Solution FirstAttempt;
	cout << "[[[]]] returns: " << FirstAttempt.isValid("[[[]]]") <<"\n";
	cout << "{}[]() returns: " << FirstAttempt.isValid("{}[]()") << "\n";
	cout << "}[]() returns: " << FirstAttempt.isValid("}[]()") << "\n";
	cout << "{{[]() returns: " << FirstAttempt.isValid("{{[]()") << "\n";
}
