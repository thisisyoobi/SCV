#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : 시스템 UMASK 값이 022 인지 아닌지 점검 */

void U_32() {
	FILE* fp;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "UMASK=022";
	int ret;

	system("grep -r 'UMASK=022' /etc/profile > output32.txt");
	if ((fp = fopen("output32.txt", "w")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(arr, sizeof(arr), fp);
	ret = strcmp(arr, setting);
	if (ret == 10)
		printf("[U-32] UMASK 설정 관리(중) : 양호\n");
	else
		printf("[U-32] UMASK 설정 관리(중) : 취약\n");

	system("rm -f output32.txt");
}
