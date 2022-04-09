#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace algo_1 {

	void print(std::string str, std::vector<int> &vec)
	{
		cout << str << "\t";
		for (auto &ix : vec) {
			cout << ix << "\t";
		}
		cout << endl;
	}
	void demo_fun()
	{
		std::vector<int> vec;
		for (int ix = 1; ix < 10; ix++) {
			vec.push_back(rand() % 100);
		}
		print("sort before: ", vec);

		sort(vec.begin(), vec.end());
		print("sort after: ", vec);

		sort(vec.rbegin(), vec.rend());
		print("rsort after: ", vec);
	}
};

int main()
{
	algo_1::demo_fun();
	return 0;
}
