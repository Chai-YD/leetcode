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

namespace name_5 {
	using namespace std;
	//测试move - 移动构造
	class example {
	public:
		example(const string& str) {
			cout << "construct" << endl;
		}
		~example() {
			cout << "destroy" << endl;
		}
		example(example&& x) {
			cout << "move" << endl;
		}
		example& operator= (example& x) {
			cout << "= " << endl;
			return *this;
		}
		example& operator= (example&& x) {
			cout << "move = " << endl;
			return *this;
		}
	};
	void demo_fun()
	{
		example ex("1111");
		example ex_1 = example("2222");
		example ex_2(move(ex));
		ex_2 = move(ex_1);
		ex_2 = ex_1;
	}
};

namespace name_6 {
	//测试 类内定义引用 成员变量 & 初始化
	class example {
	public:
#if 0
		//构造函数内部初始化异常
		example (int val)
		{
			_val = val;
		}
#endif
		//构造函数的形参可以为引用类型，也可以不为引用类型；
		//引用成员变量的初始化必须在初始化链表中进行；
		example (int val)
			:_val(val)
		{
		}
		~example ()
		{
		}
		void print()
		{
			cout << _val << endl;
		}
	private:
		int &_val;
	};
	void demo_fun()
	{
		int val = 1;
		class example t_ex(val);
		t_ex.print();
	}
};

namespace name_7 {
	//测试 常量成员函数 修改 成员变量
	class example {
	public:
		example (int val)
			:_val(val)
		{
		}
		~example ()
		{
		}
		void print() const
		{
			//const 成员函数 不能对成员变量进行修改
			//_val = 1;
			cout << _val << endl;
		}
		void set()
		{
			_val = 1;
		}
	private:
		int _val;
	};
	void demo_fun()
	{
		class example t_ex(1);
		t_ex.print();
	}
};

namespace name_8 {
	// 64位系统下，指针占8字节，虚继承 & 虚函数 都占用8字节
	// 64位系统下, 默认对齐数为8
	class fa{
	public:
		fa ()
		{
		}
		~fa ()
		{
		}
		virtual void f()
		{
			cout << "fa::f()" << endl;
		}
	private:
		int fa_a;
	};
	class fa1 : virtual public fa{
	public:
		fa1 ()
		{
		}
		~fa1 ()
		{
		}
		virtual void f()
		{
			cout << "fa1::f()" << endl;
		}
		virtual void f1()
		{
			cout << "fa1::f1()" << endl;
		}
	private:
		int fa1_a;
	};
	class fa2 : virtual public fa{
	public:
		fa2 ()
		{
		}
		~fa2 ()
		{
		}
		virtual void f()
		{
			cout << "fa2::f()" << endl;
		}
		virtual void f2()
		{
			cout << "fa2::f2()" << endl;
		}
	private:
		int fa2_a;
	};
	class ch : public fa1, public fa2
	{
	public:
		virtual void fun1()
		{
		}
		virtual void f()
		{
			cout << "ch::f()" << endl;
		}
		virtual void c()
		{
			cout << "ch::c()" << endl;
		}
	private:
		int a;
	};
	void demo_fun()
	{
		typedef void (*FUN)();
		class ch t_ch;
		int ** vbptr = (int **)&t_ch;
		FUN t_fun = reinterpret_cast<FUN>(vbptr[0][0]);
		t_fun();
	}
};
namespace name_9 {
	class example {
	public:
		example ()
		{
		}
		~example ()
		{
		}
		virtual void f() = 0;
	private:
	};
	class ch : public example{
	public:
		ch()
		{
		}
		~ch()
		{
		}
		void f()
		{
			cout << "f" << endl;
		}
	private:
	};
	void demo_fun()
	{
		//包含纯虚函数的类不能进行实例化
		//class example t_ex;
		class ch t_Ch;
	}
};
namespace name_10 {
	//验证构造函数中调用虚函数是否能够实现多态效果
	//结果： 不能实现多台效果；没有意义
	class example {
	public:
		example ()
		{
			f();
		}
		~example ()
		{
		}
		virtual void f ()
		{
			cout << "example::f()" <<endl;
		}
	private:
	};
	class ch : public example {
	public:
		ch()
		{
		}
		~ch()
		{
		}
		void f ()
		{
			cout << "ch::f()" <<endl;
		}
	private:
	};
	void demo_fun()
	{
		class ch t_ch;
	}
};

//命名空间模板
namespace name_x {
	class example {
	public:
		example ()
		{
		}
		~example ()
		{
		}
	private:
	};
	void demo_fun()
	{
	}
};

int main()
{
	name_10::demo_fun();
	return 0;
}
