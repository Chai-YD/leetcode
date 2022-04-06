#include <iostream>
#include <unordered_map>

/*泛化*/
template <typename size_type, typename num_type>
class counter {
private:
	size_type _size = 0;
	num_type _num = 0;
public:
	void update_counter(size_type size, num_type num) {
		_size += size;
		_num += num;	
	}
	size_type get_size() {
		return _size;
	}
	num_type get_num() {
		return _num;
	}
};

/*全特化*/
template<> class counter<int, int> {
private:
	int _size = 0;
	int _num= 0;
public:
	void update_counter(int size, int num) {
		//std::cout << "update_counter<int, int>" << std::endl;
		_size += size;
		_num += num;	
	}
	int get_size() {
		return _size;
	}
	int get_num() {
		return _num;
	}
}; 

/*装饰器模式*/
class task_counter {
public:
	void update_counter(unsigned short taskid, int size, int num) {
		_umap[taskid].update_counter(size, num);
	}
	int get_size(unsigned short taskid) {
		return _umap[taskid].get_size();
	}
	int get_num(unsigned short taskid) {
		return _umap[taskid].get_num();
	}

	void print()
	{
		for (auto it = _umap.begin(); it != _umap.end(); it++) {
			std::cout << "[ " << it->first << " ]" << std::endl;
			std::cout << "\tsize = " << it->second.get_size() << std::endl;
			std::cout << "\tnum = " << it->second.get_num() << std::endl;
		}
	}

private:
	//unordered_map 使用
	std::unordered_map<unsigned short, counter<int, int>> _umap;
};

void demo_task_counter()
{
	class task_counter tcoun;
	for (int jx = 1; jx <= 3; jx++) {
		for (int ix = 1; ix <= 10; ix++) {
			tcoun.update_counter(jx, ix, ix);
		}
	}
	tcoun.print();
}

int main()
{
	demo_task_counter();
	return 0;
}
