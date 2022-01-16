#include <iostream.h>

class mod_sort 
{
private:
	int cnt = 0;
	int mod = 1000000007;
	vector<int> vec;
	priority_queue<int> min_heap;
	priority_queue<int, vector<int>, greater<int> > max_heap;
public:
	int duplicate(vector<int>& numbers);

	void merge(vector<int> &data, int start, int mid, int end);
	void mergesort(vector<int> &data, int start, int end);
	int InversePairs(vector<int> data);

	int mergeSort_ex(int left, int right, vector<int>& data, vector<int>& temp);
	int InversePairs_ex(vector<int> data);

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
	vector<int> GetLeastNumbers_Solution_ex(vector<int> input, int k);

	void Insert(int num);
	double GetMedian();
	void Insert2(int num);
	double GetMedian2();
};
