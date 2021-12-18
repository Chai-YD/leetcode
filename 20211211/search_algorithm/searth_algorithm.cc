
#include "search_algorithm.h"

int search_algorithm::__FindK(vector<int> data, int left, int right, int k)
{
	if (left < 0 || right < 0 || right <= left) {
		return -1;
	}

	int mid = (right - left) / 2 + left;

	if (data[mid] == k) {
		return mid;
	}
	else if (data[mid] > k)	{
		if (mid > left && (mid = __FindK(data, left, mid, k)) != -1) {
			return mid;
		}
	}
	else if (data[mid] < k) {
		if (right > mid + 1 && (mid = __FindK(data, mid + 1, right, k)) != -1) {
			return mid;
		}
	}


	return -1;
}

int search_algorithm::GetNumberOfK(vector<int> data, int k)
{
	if (data.empty()) {
		return 0;
	}

	int mid = -1;
	int count = 0;
	mid = __FindK(data, 0, data.size(), k);
	if (mid == -1) {
		return 0;
	}

	int len = 0;
	for (int ix = mid; ix >= 0; ix--) {
		if (data[ix] == k) {
			count++;
		}
		else {
			break;
		}
	}
	for (int ix = mid + 1; ix < data.size(); ix++) {
		if (data[ix] == k) {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}
bool search_algorithm::Find(int target, vector<vector<int> > array)
{
	int rows = array.size();
	int cols = array[0].size();

	int ix = 0, jx = cols - 1;
	while (ix < rows && jx >= 0) {
		if(array[ix][jx] == target) {
			return true;
		}
		else if (array[ix][jx] < target) {
			ix++;
		}
		else {
			jx--;
		}
	}
	return false;
}

int search_algorithm::__getMinNum(vector<int> arr, int left, int right)
{
	if (left == right) {
		return arr[left];
	}
	if (right - left  == 1) {
		return arr[left] > arr[right] ? arr[right] : arr[left];
	}
	int mid = (right - left) / 2 + left;
	if (arr[mid] > arr[right]) {
		return __getMinNum(arr, mid, right);
	}
	else if (arr[left] == arr[right]) {
		return min(__getMinNum(arr, left, mid), __getMinNum(arr, mid, right));
	}
	else {
		return __getMinNum(arr, left, mid);
	}
}
int search_algorithm::minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.size() == 0) {
		return -1;
	}
	if (rotateArray.size() == 1) {
		return rotateArray[0];
	}
	if (rotateArray.size() == 2) {
		return rotateArray[0] > rotateArray[1] ? rotateArray[1] : rotateArray[0];
	}
	return __getMinNum(rotateArray, 0, rotateArray.size() - 1);
}

void search_alorithm::__Permutation(vector<char> vec, int begin)
{
	if (vec.size() <= begin) {
		string tmp(vec.begin(), vec.end());
		ret_vec.push_back(tmp);
		return;
	}

	sort(vec.begin() + begin, vec.end());

	for (int ix = begin; ix < vec.size(); ix++) {
		if (ix > begin && vec[ix] == vec[ix - 1]) {
			continue;
		}
		//交换
		char tmp = vec[begin];
		vec[begin] = vec[ix];
		vec[ix] = tmp;
		__Permutation(vec, begin + 1);
		//还原
		tmp = vec[begin];
		vec[begin] = vec[ix];
		vec[ix] = tmp;
	}
}

vector<string> search_alorithm::Permutation(string str)
{
	if (str.empty()) {
		return vec;
	}
	vector<char> vec;
	for (auto ix : str) {
		vec.push_back(ix);
	}
	__Permutation(vector, 0);
	return vec;
}
