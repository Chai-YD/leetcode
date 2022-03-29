#include <iostream>

#if 0
内存问题:
1. 内存泄露常见操作
{
	new 和 malloc申请资源使用后，未调用delete和free进行释放；
	子类继承父类时，父类析构函数不是虚函数；
}
2. 检测内存泄露
{
	良好的编程习惯，申请 与 释放配对；
	申请内存进行管理，程序结束前统一处理；
	工具检测：valgrind；
	使用智能指针；
}

#endif

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

#if 0
内存对齐：
	内存对齐应用于三种数据类型：struct、class、union
	每个数据成员存储的起始位置要从该成员大小或者成员大小的整数倍开始；
	结构体总大小为最宽字符的整数倍；
#endif
namespace bb { //内存对齐
	using namespace std;
	union un {
		int a;
		char b;
		double c;
	};

	struct st {
		int a;
		char b;
		double c;
	};

	class cl {
	public:
		int a;
		char b;
		char b1;
		double c;
	};

	class cl_ex {
	public:
		double c;
		char b;
		int a;
		char b1;
	};

	void demo()
	{
		union un t_un;
		struct st t_st;
		class cl t_cl;
		class cl_ex t_cl_ex;

		cout << "union: " << sizeof(t_un) <<endl;
		cout << "struct: " << sizeof(t_st) <<endl;
		cout << "class: " << sizeof(t_cl) <<endl;
		cout << "class_ex: " << sizeof(t_cl_ex) <<endl;
	}

};

void demo_bb()
{
	bb::demo();
}

void demo_aa()
{
	int ix = 1;
	if (ix == 1) {
		class aa::fat *fa = NULL;
		fa = new aa::chi();
		delete fa;
	}
	else if (ix == 2) {
		class aa::chi *ci = new aa::chi();
		delete ci;
	}
}

int main()
{
	demo_aa();
	demo_bb();
	return 0;
}
