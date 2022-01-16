#include <iostream.h>

class mod_sort 
{
private:
	int cnt = 0;
	int mod = 1000000007;
public:
	int duplicate(vector<int>& numbers);

	void merge(vector<int> &data, int start, int mid, int end);
	void mergesort(vector<int> &data, int start, int end);
	int InversePairs(vector<int> data);

	int mergeSort_ex(int left, int right, vector<int>& data, vector<int>& temp)
	int InversePairs_ex(vector<int> data); ;

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
	void Insert(int num);
	double GetMedian();
};
