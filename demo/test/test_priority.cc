#include <stdio.h>


enum priority {
	MOD_TASK_PRIORITY_MIN = 0,
	MOD_TASK_PRIORITY_H = 1,
	MOD_TASK_PRIORITY_M,
	MOD_TASK_PRIORITY_L,
	MOD_TASK_PRIORITY_MAX,
};

#if 0
结构体初始化（C pk C+_+）
	C语言中可对结构体中数据进行指定初始化，初始化顺序不受限制；
	C++语言中，结构体数据必须按照顺序进行初始化；
#endif
const char *num2str[MOD_TASK_PRIORITY_MAX] = {
	[MOD_TASK_PRIORITY_MIN] = "udpmover:list:unless",
	[MOD_TASK_PRIORITY_H] = "udpmover:list:priority_hig",
	[MOD_TASK_PRIORITY_M] = "udpmover:list:priority_mid",
	[MOD_TASK_PRIORITY_L] = "udpmover:list:priority_low",
};


int main()
{
	for (int ix = 0; ix < MOD_TASK_PRIORITY_MAX; ix++) {
		printf("%d : %s.\n", ix, num2str[ix]);
	}
	return 0;
}
