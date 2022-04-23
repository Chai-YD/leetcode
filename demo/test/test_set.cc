#include <iostream>
#include <unordered_set>

using namespace std;
void demo_set()
{
	unordered_set<int> mset;

	for (int ix = 0; ix < 100; ix++) {
		if (ix % 10 == 0) {
			cout << "mset.size : " << mset.size() << endl;;
		}
		mset.insert(ix % 10);
	}
	for (const auto &it : mset) {
		cout << it << endl;	
	}
}

int main() {
	demo_set();
}
