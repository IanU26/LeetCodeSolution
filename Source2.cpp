/*

// Leetcode 9: Palidrome Number
// Here I am using the code from Leetcode 7 (Reverse Integer) and applying a check if it matches the original output.

#include <iostream>

class Solution {
public:
	bool isPalindrome(int x) {
		int test = x;
		int sum = 0;
		int ten = 10;
		if (x < 0) {
			return 0;
		}

		while (x != 0) {
			if (sum > INT_MAX/10) return 0;
			if (sum < INT_MIN/10) return 0;
			// ( x % 10 ) takes the last digit from the input. 
			// ( sum * ten ) pushes the current sum over so that the last digit may be placed. 
			
			sum = (sum * ten) + (x % ten);
			x = x / 10;
		}
		return test == sum;
	}
};

int main() {
	//Solution Firstattempt;
	//std::cout << Firstattempt.isPalindrome(121);
	

}



*/