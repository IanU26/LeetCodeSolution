
// LeetCode 1: Two Sum 
// SOLVED
// METHOD: One go through. Traverse the vector and input the values (of the vector) as keys (in a hashmap) and 
// the location of the value (in the vector 0,1,2,etc.) as the T (in the hashmap). The loop starts by subtracting the target
// by the current value in the vector(yielding the number needed to add to the target) and checking if it is in the hashmap. 
// If the necessary value is in the hashmap then the current value's location is returned as well as the location of the 
// necessary value (which is a T in the hashmap). 

#include <iostream>
#include <unordered_map>

class Solution {
public:
	std::unordered_map<int, int> umap;
	int first;
	int second;
	//The first std::vector<int> is declaring what will be returned by this member function. In this case it is a vector.
	//The name of this member fuction is twoSum. 
	//The parameters for twoSum is a vector and an integer.
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			int x = target - nums[i];
			//Found the answer. Return the location of 'x' from the hashmap and 'i' the location in the original vector.
			if (umap.find(x) != umap.end()) {
				first = umap[x];
				second = i;
				break;
			}
			else {
				umap[nums[i]] = i;
			}
		}
		std::vector<int> vect = {first, second};
		return vect;
	}
};

//Example with input vector being (3,2,4)
int main() {
	Solution FirstAttempt;
	std::vector<int> v = {3,2,4};
	int target = 6;
	std::vector<int> sol = FirstAttempt.twoSum(v, target);
	std::cout << sol[0] << sol[1];

	return 0;
}



//Notes on how to use hashmaps and vectors. 

/*
//How to create a Hashmap and access a single value in the Hashmap. 
//All that is required is defining what datatype will be used. 
int main() {
	std::unordered_map<std::string, int> umap;
	umap["zero"] = 0;
	umap["one"] = 1;
	umap["two"] = 2;
	umap["three"] = 3;
	umap["four"] = 4;
	
	if (umap.find("zero") != umap.end()) {
		std::cout << umap["one"];
	}
	return 0;
}
*/

/*
//Working with vectors
int main() {
	std::vector<int> nums = { 10,20,30 };
	std::cout << nums[0];
}

*/
