#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#if 0
多线程调试：
	info thread:	查看线程信息;
	thread id:		切换线程；
	scheduler-locking:	设置线程调试方式
	break location thread id:	指定线程上设置断点；
	thread apply id command:	指定线程上执行命令；
参考文献：
	https://note.youdao.com/web/#/file/WEB7f253ec40307b995d678f8c28f8d26cf/note/wcp165078395868717/
#endif

void *thread_fun(void *name) {
	char *thread_name = (char *)name;
	cout << thread_name << endl;
	return NULL;
}

void demo_thread(int num)
{
	vector<pthread_t> vec;
	char thread_info[1024];
	for (int ix = 0; ix < num; ix++) {
		pthread_t pid;
		snprintf(thread_info, 1024, "thread%d_job", ix);	
		cout << ix << " : " << thread_info << endl;
		pthread_create(&pid, NULL, thread_fun, thread_info);
		vec.push_back(pid);
		sleep(1);
	}

	sleep(3);

	for(auto &it : vec) {
		cout << "pthread_t: " << it << endl;
		pthread_join(it, NULL);
	}
}

int main()
{
	int num = 3;
	demo_thread(num);
	return 0;
}
