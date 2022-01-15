#include "dynamic_programming.h"


int dynamic_programming::FindGreatestSumOfSubArray(vector<int> array)
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
int dynamic_programming::jumpFloorII(int number)
{
	if (number == 1) {
		return 1;
	}
	else if (number == 2) {
		return 2;
	}
	int arr[21] = {0};
	arr[1] = 1;
	arr[2] = 2;

	for (int ix = 3; ix <= number; ix++) {
		for (int jx = ix - 1; jx > 0; jx--) {
			arr[ix] += arr[jx]; 
		}
		arr[ix] += 1;
	}

	return arr[number];
}
int dynamic_programming::rectCover(int number)
{
	if (number <= 0) {
		return 0;
	}
	if (number == 1) {
		return 1;
	}
	if (number == 2) {
		return 2;
	}
	int left = 1;
	int right = 2;
	for (int ix = 3; ix <= number; ix++) {
		int tmp = left;
		left = right;
		right += tmp;
	}

	return right;
}
int dynamic_programming::maxProfit(vector<int>& prices)
{
	int ret = 0;
	if (prices.size() == 0) {
		return ret;
	}
	int cur = prices[0];
	for (int ix = 1; ix < prices.size(); ix++) {
		if (cur > prices[ix]) {
			cur = prices[ix];
		}
		else {
			if (prices[ix] - cur > ret) {
				ret = prices[ix] - cur;
			}
		}
	}

	return ret;
}

int dynamic_programming::__maxValue(vector<vector<int> >& grid, int cur_val, int row, int col, int rows, int cols)
{
	if (row + 1 == rows && col + 1 == cols) {
		return cur_val;
	}
	if (row + 1 == rows) {
		return __maxValue(grid, cur_val + grid[row][col + 1], row, col + 1, rows, cols);
	}
	else if (col + 1 == cols) {
		return __maxValue(grid, cur_val + grid[row + 1][col], row + 1, col, rows, cols);
	}
	else {
		return max(__maxValue(grid, cur_val + grid[row][col + 1], row, col + 1, rows, cols),
				__maxValue(grid, cur_val + grid[row + 1][col], row + 1, col, rows, cols));
	}
}

int dynamic_programming::maxvalue(vector<vector<int> >& grid)
{
	return __maxvalue(grid, grid[0][0], 0, 0, grid.size(), grid[0].size());
}

int dynamic_programming::maxvalue2(vector<vector<int> >& grid)
{
	int rows = grid.size();
	int cols = grid[0].size();

	if (rows <=0 || cols <= 0) {
		return 0;
	}

	int *max_val = new int[cols];

	for (int ix = 0; ix < rows; ix++) {
		for (int jx = 0; jx < cols; jx++) {
			int left = 0;
			int up = 0;
			if (ix > 0) {
				up = max_val[jx];
			}
			if (jx > 0) {
				left = max_val[jx - 1];
			}
			max_val[jx] = max(up, left) + grid[ix][jx];
		}
	}

	int result = max_val[cols - 1];
	delete[] max_val;

	return result; 
}

int dynamic_programming::lengthOfLongestSubstring(string s)
{
	int maxlen = 0;
	unordered_set<char> chars;
	for (int ix = 0; ix < s.size(); ix++) {
		int len = 1;
		chars.clear();
		chars.insert(s[ix]);
		for (int jx = ix + 1; jx < s.size(); jx++) {
			if (chars.count(s[jx])) {
				break;
			}
			else {
				chars.insert(s[jx]);
				len++;
			}
		}
		maxlen = max(maxlen, len);
	}

	return maxlen;
}

int dynamic_programming::lengthOfLongestSubstring2(string s)
{
	int maxlen = 0;
	if (s.size() == 0) {
		return 0;
	}
	unordered_set<char> chars;
	int right = 0;
	for (int left = 0; left < s.size(); left++) {
		while (right < s.size() && !chars.count(s[right])) {
			chars.insert(s[right]);
			right++;
		}
		maxlen = max(maxlen, right - left);
		if (right == s.size()) {
			break;
		}
		chars.erase(s[left]);
	}

	return maxlen;
}

int dynamic_programming::lengthOfLongestSubstring3(string s)
{
	vector<int> m(128, -1);
	int res = 0, left = -1;
	for (int ix = 0; ix < s.size(); ix++) {
		left = max(left, m[s[ix]]);
		m[s[ix]] = ix;
		res = max(res, ix - left);
	}

	return res;
}

int dynameic_programming::solve(string nums)
{
	if (nums.size() == 0) {
		return 0;
	}

	vector<int> dp(nums.size() + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	if (nums.size() == 1 && nums[0] - '0' == 0) {
		return 0;
	}

	for (int ix = 2; ix <= nums.size(); ix++) {
		int tmp = (nums[ix - 2] - '0') * 10 + nums[ix - 1] - '0';
		if ((tmp > 10 && tmp < 20) || (tmp > 20 && tmp <= 26)) {
			dp[ix] = dp[ix - 1] + dp[ix - 2];
		}
		else if (tmp == 10 || tmp == 20) {
			dp[ix] = dp[ix - 2];
		}
		else if (tmp == 0) {
			return 0;
		}
		else {
			dp[ix] = dp[ix - 1];
		}
	}

	return dp[nums.size()];
}

