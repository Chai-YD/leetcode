#include <stdio.h>


class dynamic_programming 
{
private:
public:
	int FindGreatestSumOfSubArray(vector<int> array);
	vector<int> FindGreatestSumOfSubArray(vector<int> &array);
	int jumpFloor(int number);
	int Fibonacci(int n);
	bool match(string str, string pattern);
	int jumpFloorII(int number);
	int rectCover(int number);
	int maxProfit(vector<int>& prices);
	int __maxValue(vector<vector<int> >& grid, int cur_val, int row, int col, int rows, int cols);
	int maxValue(vector<vector<int> >& grid);
	int maxValue2(vector<vector<int> >& grid);
	int lengthOfLongestSubstring(string s);
};
