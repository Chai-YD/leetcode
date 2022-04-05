#include <iostream>
#include <cstdlib>
#include <algorithm>


using namespace std;
void demo_perf()
{
	int arr[10000];

	for (int ix = 0; ix < 10000; ix++) {
		arr[ix] = rand() % 256;
	}

	//sort 提升程序性能, 降低branch-miss
	//sort(arr, arr + 10000);
	long long sum = 0;

	for ( int ix = 0; ix < 30000; ix++) {
		for (int jx = 0; jx < 10000; jx++) {
			if (arr[jx] >= 128) {
				sum += arr[jx];
			}
		}
	}

	cout << "sum = " << sum <<endl;
}

int main ()
{
	demo_perf();
	return 0;
}
