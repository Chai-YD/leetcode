#include <iostream>

class search_algorithm
{
private:
	vector<string> vec;
public:
	int GetNumberOfK(vector< int> data, int k);
	bool Find(int target, vector<vector<int> > array);
	int getMinNum(vector<int> arr, int left, int right);
	int minNumberInRotateArray(vector<int> rotateArray);
	vector<string> Permutation(string str);
};
