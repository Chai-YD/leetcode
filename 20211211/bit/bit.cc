
#include "bit.h"

int mod_bit::Add(int num1, int num2)
{
	int add = num1;
	int sum = num2;
	while (add) {
		int tmp = add ^ sum;
		add = (add & sum) << 1;
		sum = tmp;
	}

	return sum;
}

int  mod_bit::NumberOf1(int n)
{
	int cnt = 0;
	while (n) {
		n &= (n - 1);
		cnt++;
	}
	return cnt;
}

double mod_bit::Power(double base, int exponent)
{
	int flag = 1;
	double ret = 1;
	if (base ==0) {
		return 0;
	}
	if (exponent == 0) {
		return 1;
	}
	if (exponent < 0) {
		flag = -1;
		exponent *= flag;
	}

	for (int ix = 1; ix <= exponent; ix++) {
		;
		ret *= base;
	}

	if (flag < 0) {
		ret = 1 / ret;
	}

	return ret;
}

vector<int> mod_bit::FindNumsAppearOnce(vector<int>& array)
{
	vector<int> ret(2);

	int res = 0;
	for (auto tmp : array) {
		res ^= tmp;
	}

	int low = 1;
	while (!(res & low)) {
		low <<= 1;
	}

	for (auto tmp : array) {
		if (tmp & low) {
			ret[0] ^= tmp;
		}
		else {
			ret[1] ^= tmp;
		}
	}

	if (ret[0] > ret[1]) {
		int tx = ret[0];
		ret[0] = ret[1];
		ret[1] = tx;
	}

	return ret;
}

vector<int> mod_bit::FindNumsAppearOnce2(vector<int>& array)
{
	unordered_map<int, int> mp;
	vector<int> ret;

	for (int tmp : array) {
		mp[tmp]++;
	}

	for (int tmp : array) {
		if (mp[tmp] == 1) {
			ret.push_back(tmp);
		}
	}

	if (ret[0] > ret[1]) {
		int tx = ret[0];
		ret[0] = ret[1];
		ret[1] = tx;
	}
}

int mod_bit::Sum_Solution(int n)
{
	n && (n += Sum_Solution(n - 1));
	return n;
}

int mod_bit::Sum_Solution2(int n)
{
	bool arr[n][n + 1];
	return sizeof(arr) >> 1;
}

int mod_bit::Sum_Solution3(int n)
{
	int ret = 0;
	int A = n;
	int B = n + 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;
	(B & 1) && (ret += A);
	B >>= 1;
	A <<= 1;

	return ret >> 1;
}
