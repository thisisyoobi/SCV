#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검 기준 : NFS 서비스 비활성화  */

void U_24() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";
	int ret1;

	system("ps -ef | egrep \"nfs|statd|lockd\" | wc -l > output24.txt");

	if ((fp = fopen("output24.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-24] world writable 파일 점검(상) : 양호\n");
	else
		printf("[U-24] world writable 파일 점검(상) : 취약\n");

	system("rm -f output24.txt");
}
