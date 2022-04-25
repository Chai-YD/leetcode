#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define true 1

void demo_1()
{
	while (true) {
		printf("aaa.\n");
	}
}

void demo_2()
{
	for(;true;) {
		printf("aaa.\n");
	}
}

void demo_3()
{
	for(;true;exit(1)) {
		printf("aaa.\n");
	}
}

void demo_4()
{
	for (;;) {
		break;
		printf("aaa.\n");
	}
}

int main(int argc, char *argv[])
{
	int opt = -1;
	int num = 1;
	while ((opt = getopt(argc, argv, "m:")) != -1) {
		switch (opt) {
			case 'm':
				num = atoi(optarg);
				break;
			default:
				printf("input invaild.\n");
		}
	}

	if (num == 1) {
		demo_1();
	}
	else if (num == 2) {
		demo_2();
	}
	else if (num == 3) {
		demo_3();
	}
	else if (num == 4) {
		demo_4();
	}
	return 0;
}
