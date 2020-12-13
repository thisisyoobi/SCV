#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : NIS 서비스 비활성화 ( 뭐가 불필요한지 몰라서 있으면 일단 취약으로 뜨게 구현함..  */

void U_31() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";
	int ret1;

	system("ps -ef | grep yp | wc -l > output31.txt");

	if ((fp = fopen("output31.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-31] NIS 서비스 비활성화(중) : 양호\n");
	else
		printf("[U-31] NIS 서비스 비활성화(중) : 취약\n");

	system("rm -f output31.txt");
}
