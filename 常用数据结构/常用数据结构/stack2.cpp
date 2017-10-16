#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
void main()
{
	int i = 0, j = 0;
	vector<vector<int>>Array(10, vector<int>(0));
	for (j = 0; i < 10; i++)
		for (i = 0; i < 9; i++)
			Array[j].push_back(i);
	for (j = 0; j < 10; j++)
		for (i = 0; i < Array[j].size(); i++)
			cout << Array[j][i] << " ";
	cout << endl;
}