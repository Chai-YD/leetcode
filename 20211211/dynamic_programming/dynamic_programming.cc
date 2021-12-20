#include "dynamic_programming.h"


int dynamic_proramming::FindGreatestSumOfSubArray(vector<int> array)
{
	if (array.empty()) {
		return -1;
	}
	int max_val = array[0];
	int cur_val = array[0];
	for (int ix = 1; ix < array.size(); ix++) {
		if (array[ix] > cur_val + array[ix]) {
			cur_val = array[ix];
		}
		else {
			cur_val += array[ix];
		}
		if (cur_val > max_val) {
			max_val = cur_val;
		}
	}
	return max_val;
}
