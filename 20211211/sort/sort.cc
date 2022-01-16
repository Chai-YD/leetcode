
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

void mod_sort::merge(vector<int> &data, int start, int mid, int end, vector<int> &res)
{
	int ix = start; jx = mid + 1;
	int cur = start;
	while (ix <= mid && jx <= end) {
		if (data[ix] > data[jx]) {
			cnt = (cnt + mid - ix + 1) % 1000000007;
			res[cnt++] = data[jx++];
		}
		else {
			res[cnt++] = data[ix++];
		}
	}
	while(ix <=mid) {
		res[cnt++] = data[ix++];
	}
	while (jx <=end) {
		res[cnt++] = data[jx++];
	}
	for (int ix = start; ix <= end; ix++) {
		data[ix] = tmp[ix];
	}
}

void mod_sort::mergesort(vector<int> &data, int start, int end, vector<int> &res)
{
	if (start < end) {
		int mid = (start + mid) >> 1;
		mergesort(data, start, mid);
		mergesort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}

int mod_sort::InversePairs(vector<int> data)
{
	int cnt = data.size();
	vector<int> res(n);
	if (cnt != 0) {
		mergesort(data, start, 0, cnt - 1, res);
	}
	return cnt;
}

int mod_sort::mergeSort_ex(int left, int right, vector<int>& data, vector<int>& temp)
{
	if (left >= right)    // 停止划分
		return 0;
	int mid = (left + right) / 2; //取中间
	int res = mergeSort(left, mid, data, temp) + mergeSort(mid + 1, right, data, temp); //左右划分
	res %= mod;  //防止溢出
	int i = left, j = mid + 1;
	for (int k = left; k <= right; k++)
		temp[k] = data[k];
	for (int k = left; k <= right; k++) {
		if (i == mid + 1)
			data[k] = temp[j++];
		else if (j == right + 1 || temp[i] <= temp[j])
			data[k] = temp[i++];
		else { //左边比右边大，答案增加
			data[k] = temp[j++];
			res += mid - i + 1; // 统计逆序对
		}
	}
	return res % mod;
}

int mod_sort::InversePairs_ex(vector<int> data)
{
	int n = data.size();
	vector<int> res(n);
	return mergeSort(0, n - 1, data, res);
}

vector<int> mod_sort::GetLeastNumbers_Solution_ex(vector<int> input, int k)
{
	vector<int> ret;

	if (k == 0 || k > input.size()) {
		return ret;
	}

	priority_queue<int, vector<int> > pq;
	for (const int val : input) {
		if (pq.size() < k) {
			pq.push(val);
		}
		else {
			if (val < pq.top()) {
				pq.pop();
				pq.push(val);
			}
		}
	}

	while (!pq.empty()) {
		ret.push_back(pq.top());
		pq.pop();
	}

	return ret;
}

vector<int> mod_sort::GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> ret;
	if (k ==0 || K>input.size()) {
		return ret;
	}
	sort(input.begin(), input.end());

	return vector<int>({input.begin(), input.begin() + k});
}

void mod_sort::Insert(int num)
{
	vec.push_back(num);
}

double mod_sort::GetMedian()
{
	sort(vec.begin(), vec.end());
	int sz = vec.size();
	if(sz & 1) {
		return (double)vec[sz >> 1];
	}
	else {
		return (double)(vec[sz>>1] + vec[(sz - 1)>>1])/2;
	}
}

void mod_sort::Insert2(int num)
{
	min_heap.push(num);
	
	max_heap.push(min_heap.top());
	min_heap.pop();

	if (min_heap.size() < max_heap.size()) {
		min_heap.push(max_heap.top());
		max_heap.pop();
	}
}

double mod_sort::GetMedian2()
{
	return min_heap.size() > max_heap.size() ? (double)(min_heap.top()) : (double)(min_heap.top() + max_heap.top())/2;
}

