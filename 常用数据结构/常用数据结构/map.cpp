#include <map>
#include <string>
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>twoSum(vector<int>&numbers, int target)
{
	//Key is the number and value is its index in the vector
	unordered_map<int, int>hash;
	vector<int>result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];
		//if numberToFind is found in map,return them
		if (hash.find(numberToFind) != hash.end()) {
			//+1 because indeces arre not zero based
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);
			return result;
		}
		//number was not found .put it in the map
		hash[numbers[i]] = i;
	}
	return result;
}
int main()
{
	vector<int>two;
	vector<int>numbers = { 1,2,3,4,5 };
	int target = 9;
	two = twoSum(numbers, target);
	cout << two[0] << two[1] << endl;
	return 0;
}
