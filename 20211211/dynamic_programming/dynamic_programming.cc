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
int dynamic_programming::jumpFloor(int number)
{
	int left = 1;
	int right = 1;
	for (int ix = 2; ix <= number; ix++) {
		int tmp = left + right;
		left = right;
		right = tmp;
	}

	return right;
}
int dynamic_programming::Fibonacci(int n)
{
	if (n == 1 || n == 2) {
		return 1;
	}
	int left = 1;
	int right = 1;
	for (int ix = 3; ix <= n; ix++) {
		int tmp = left + right;
		left = right;
		right = tmp;
	}

	return right;
}

bool dynamic_programming::__isMatch(const string s, const string p, int i, int j)
{
	if(p[j - 1] == '.') return true;
	return s[i - 1] == p[j - 1];
}

bool dynamic_programming::match(string str, string pattern)
{
	int m = str.length();
	int n = pattern.length();

	bool dp[m + 1][n + 1];
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;

	for (int jx = 2; jx <= n; jx++) {
		if (pattern[jx - 1] == '*') {
			dp[0][jx] = dp[0][jx - 2];
		}
	}

	for (int ix = 1; ix <= m; ix++) {
		for (int jx = 1; jx <= n; jx++) {
			if (pattern[jx - 1] == '*') {
				dp[ix][jx] |= dp[ix][jx - 2];
				if (__isMatch(str, pattern, ix, jx - 1)) {
					dp[ix][jx] |= dp[ix - 1][jx];
				}
			}
			else {
				if (__isMatch(str, pattern, ix, jx)) {
					dp[ix][jx] |= dp[ix - 1][jx - 1];
				}
			}
		}
	}

	return dp[m][n];
}
