#include <iostream>
#include <map>

using namespace std;

void demo_map_insert(map<int, int> &map, int c_num, int num)
{
	cout << "demo_map_insert" <<endl;
	if (c_num < 4  || c_num > 10) {
		c_num = 4;
	}

	for (int ix = 0; ix < num; ix++) {
		map[ix % c_num] += 1;
	}
}

void demo_map_print_by_channel(map<int, int> &map, int c_num)
{
	cout << "demo_map_print_by_channel" <<endl;
	if (c_num < 4) {
		c_num = 4;
	}

	for (int ix = 0; ix < c_num; ix++) {
		cout << ix << " : " << map[ix] <<endl;
	}
}

void demo_map_print(map<int, int> &map)
{
	cout << "demo_map_print" <<endl;
	for (auto it = map.begin(); it != map.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
	for (const auto &it : map) {
		cout << it.first << " : " << it.second << endl;
	}
}

int main()
{
	map<int, int> m_map;
	int c_num = 4;
	int num = 10;

	demo_map_print_by_channel(m_map, c_num);
	demo_map_insert(m_map, c_num, num);
	demo_map_print(m_map);
	return 0;
}
