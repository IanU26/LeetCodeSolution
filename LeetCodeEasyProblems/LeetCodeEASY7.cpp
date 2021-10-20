//LeetCode 7: Reverse Integer

//Problem: Taking in an integer, return the reverse of the integer. 


//First Thoughts: Cast the input integer to a string and switch individual numbers to get the 
//desired output. This is time consuming. 
//Best Solution: Leave the input as an int and utilize the modulus operator to access the last number of the input.
//This number is then added to 'sum'. Every iteration 'sum' is multiplied by 10 to make room for the next number in the 
//input. 

#include <iostream>
#include <string>

class Solution {
public:
	int reverse(int x) {
		int sum = 0;
		int ten = 10;
		while (x != 0) {
			if (sum > INT_MAX/10) return 0;
			if (sum < INT_MIN/10) return 0;
			// ( x % 10 ) takes the last digit from the input. 
			// ( sum * ten ) pushes the current sum over so that the last digit may be placed. 
			sum = (sum * ten) + (x % ten);
			x = x / 10;
		}
		return sum;
	}
};

int main() {
	Solution firstattempt;
	std::cout << firstattempt.reverse(12345);
}


