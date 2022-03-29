#include <iostream>

namespace aa { //继承，父类析构函数分析
using namespace std;
class fat
{
public:
	fat()
	{
		cout << "fat construct" << endl;
	}
	/*
	 * 注意：
	 *	父类中的析构函数为非虚析构函数，字类继承父类，是否资源时，不调用父类的析构函数
	 * */
#if 1
	~fat()
	{
		cout << "fat destroy" << endl;
	}
#else 
	virtual ~fat()
	{
		cout << "fat destroy" << endl;
	}
#endif
};

class chi : public fat
{
public:
	chi()
	{
		cout << "chi construct" << endl;
	}

	~chi()
	{
		cout << "chi destroy" << endl;
	}
};
};

int main()
{
	int ix = 2;
	if (ix == 1) {
		//影响
		class aa::fat *fa = NULL;
		fa = new aa::chi();
		delete fa;
	}
	else if (ix == 2) {
		//不影响
		class aa::chi *ci = new aa::chi();
		delete ci;
	}
	return 0;
}
