#include <iostream>
#include <pthread.h>
#include <string.h>
#include <vector>
#include <unistd.h>

#if 0
测试多线程情况下，strtok & strtok_r的安全性
结果：
	strtok 结果异常 & 存在崩溃现象；
	strtok_r 结果正常;
#endif
using namespace std;
void *demo_strtok(void *pix)
{
	char str[] = "ab,cd,ef,gh,ab,cd,ef,gh,ab,cd,ef,gh";
	char *ptr;
	char *ptoken;
	int *pval = (int *)pix;
	vector<char *> vec;
	while (true) {
#if 0
		ptr = strtok_r(vec.size() == 0 ? str : NULL, ",", &ptoken);
#else
		ptr = strtok(vec.size() == 0 ? str : NULL, ",");
#endif
		sleep(1);
		if (!ptr) {
			break;
		}
		vec.push_back(ptr);
	}

	cout << *pval << pthread_self() << ":\t";
	for (auto tmp : vec) {
		cout << tmp << "\t";
	}
	cout << endl;

	return NULL;
}

int main()
{
	int ret = -1;
	vector<pthread_t> vec; 

	for (int ix = 0; ix < 10; ix++) {
		pthread_t pid;
		ret = pthread_create(&pid, NULL, demo_strtok, &ix);
		if (ret != 0) {
			cout << "pthread_create: " << ix << "failed." << endl;
		}
		else {
			vec.push_back(pid);
		}
	}

	for (auto tmp : vec) {
		pthread_join(tmp, NULL);
	}
	return 0;
}
