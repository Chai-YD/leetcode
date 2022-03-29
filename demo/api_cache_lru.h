
#include <iostream>

class lru_cache
{
private:
	int _capacity;
	int _size;
	list<pair<int, int>> _data;
	unordered_map<int, list<pair<int, int>>::iterator> _map;

public:
	lru_cache(int capacity)
	{
		_capacity = capacity;
		_size = 0;
	}

	void print();
	void put(int key, int val);
	int get(int key);
};
