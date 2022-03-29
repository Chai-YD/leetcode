#include <iostream>

using namespace std;

namespace name_0 {
	int func(int a, int b)
	{
		return ((a) + (b));
	}

	int func(int a, double b)
	{
		return ((a) + (b));
	}
	int func(int a, float b)
	{
		return ((a) + (b));
	}

};

namespace name_1 {
	class has_ptr {
		public:
			has_ptr()
			{
				cout << "construct" <<endl;
			}
			~has_ptr()
			{
				cout << "destroy" <<endl;
			}

			has_ptr(has_ptr &ph)
			{
				cout << "construct ex" << endl;
			}
		private:
	};

	void demo_has_ptr(has_ptr hp)
	{
		has_ptr ret = hp;
	}

	void demo_1()
	{
		has_ptr hp;
		cout << "demo_has_ptr before" << endl;
		demo_has_ptr(hp);
		cout << "demo_has_ptr after" << endl;
	}
};

namespace name_2 {
	// 类对象初始化顺序：父类、组合类、自身类；
	// 成员变量的初始化与声明顺序有关；
	// 构造函数的调用顺序是类派生列表中的顺序；
	class fa {
	public:
		fa()
		{
			cout << "fa construct" << endl;
		}
		~fa()
		{
			cout << "fa destroy" << endl;
		}
	};

	class fa1 {
	public:
		fa1()
		{
			cout << "fa1 construct" << endl;
		}
		~fa1()
		{
			cout << "fa1 destroy" << endl;
		}
	};

	class fr {
	public:
		fr()
		{
			cout << "fr construct" << endl;
		}
		~fr()
		{
			cout << "fr destroy" << endl;
		}
	};

	class ch : public fa , fa1 {
	public:
		ch()
			:fa1(), fa()
		{
			cout << "ch construct" << endl;
		}
		~ch()
		{
			cout << "ch destroy" << endl;
		}
	public:
		class fr t_fr;
	};

	void demo_fun()
	{
		class ch t_ch;
	}
};

namespace name_3
{
	class fa {
	public:
		fa()
		{
			cout << "fa construct" << endl;
		}
#if 0
		~fa()
		{
			cout << "fa destroy" << endl;
		}
#else
		virtual ~fa()
		{
			cout << "fa destroy" << endl;
		}
#endif
	};

	class ch : public fa {
	public:
		ch()
		{
			cout << "ch construct" << endl;
		}
		~ch()
		{
			cout << "ch destroy" << endl;
		}
	public:
	};

	void demo_fun()
	{
		class ch *t_ch = new ch;
		class fa *t_fa = t_ch;

		delete t_fa;
	}
};

namespace name_4 {
	template <class T>
	struct templete_struct{
		templete_struct()
		{
			cout << sizeof(T) << endl;
		}
	};

	//显示实例化
	template struct templete_struct<int>;
	//模板具体化
	template<> struct templete_struct<double>
	{
		templete_struct()
		{
			cout << "_8__" << endl;
		}
	};
	void demo_fun()
	{
		struct templete_struct<int> tm_i;
		struct templete_struct<double> tm_d;
		//隐式实例化
		struct templete_struct<char> tm_c;
	}
};

int main()
{
	name_4::demo_fun();
	return 0;
}
