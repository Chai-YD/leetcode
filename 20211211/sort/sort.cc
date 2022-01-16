
#include "sort.h"

int mod_sort::duplicate(vector<int>& numbers)
{
	int arr[10000] = {0};

	for (int ix = 0; ix < numbers.size(); ix++) {
		if (arr[numbers[ix]] == 0) {
			arr[numbers[ix]]++;
		}
		else {
			return numbers[ix];
		}
	}

	return -1;
}

int mod_sort::InversePairs(vector<int> data)
{
}

vector<int> mod_sort::GetLeastNumbers_Solution(vector<int> input, int k)
{
}

void mod_sort::Insert(int num)
{
}

double mod_sort::GetMedian()
{
}

