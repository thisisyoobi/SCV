#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : /dev에 존재하지 않는 device 파일 점검 */

void U_27() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret1;

	system("find /dev -type f -exec ls -l {} \\; | wc -l > output27.txt");

	if ((fp = fopen("output27.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-27] /dev에 존재하지 않는 device 파일 점검(상) : 양호\n");
	else
		printf("[U-27] /dev에 존재하지 않는 device 파일 점검(상) : 취약\n");

	system("rm -f output27.txt");
}
