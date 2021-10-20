// Leetcode 13: Roman Numeral To Integer

//Problem: Given a roman numeral input, output the integer value. 

//The key was to realize you can simply loop through each value in the input 
// Add if the current numeral is larger. Subtract if the current value is smaller.

#include <iostream>
#include<unordered_map>


class Solution {
public:
	int romanToInt(std::string s) {
		std::unordered_map<char, int> umap = {
			{'I',1},
			{'V',5},
			{'X',10},
			{'L',50},
			{'C',100},
			{'D',500},
			{'M',1000}
		};


		int temp = 0;

		for (int i = 0; i <= s.length() - 1; ++i) {
			if (s[i] < s[i+1]) {
				temp -= umap[s[i]];
			}
			else {
				temp += umap[s[i]];
			}

		}
		return temp;
	}
};


int main() {
	Solution FirstAttempt;
	std::cout << FirstAttempt.romanToInt("IV");


}
