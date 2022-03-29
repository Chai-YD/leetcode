
#include "api_cache_lru.h"

void lru_cache::print()
{
	for (auto& val : _data) {
		cout << val.first << ": " << val.second << ";"
	}
	cout << endl;
}

void lru_cache::put(int key, int val)
{
	if (_map.find(key) != _map.end()) {
		_data.erase(_map[key]);
		--_size;
	}
	else if (_size >= _capacity) {
		_map.erase(_data.back().first);
		_data.pop_back();
		--_size;
	}
	_data.push_front({key, val});
	_map[key] = _data.begin();
	++_size;
}

int lru_cache::get(int key)
{
	if (_map.find(key) != _map.end()) {
		put(key, _map[key]->second);
		return _map[key]->second;
	}

	return -1;
}

