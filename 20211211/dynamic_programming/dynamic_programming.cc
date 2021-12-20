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

vector<int> dynamic_programming::FindGreatestSumOfSubArray(vector<int> &array)
{
	vector<int> vec;
	if (array.empty()) {
		return vec;
	}
	int max_val = array[0];
	int cur_val = array[0];

	int ret_left = 0;
	int ret_right = 0;

	int cur_left = 0;
	int cur_right = 0;
	for (int ix = 1; ix < array.size(); ix++) {
		if (array[ix] > cur_val + array[ix]) {
			cur_val = array[ix];
			cur_left = cur_right = ix;
		}
		else {
			cur_val += array[ix];
			cur_right = ix;
		}
		if (cur_val >= max_val) {
			max_val = cur_val;
			ret_left = cur_left;
			ret_right = cur_right;
		}
	}

	for(int ix = ret_left; ix <= ret_right; ix++) {
		vec.push_back(array[ix]);
	}

	return vec;
}
