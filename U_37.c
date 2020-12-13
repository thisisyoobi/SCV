#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : Anonymous FTP 비활성화 점검 */

void U_37() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret1;

	system("cat /etc/passwd | grep \"ftp\" | wc -l > output37.txt");

	if ((fp = fopen("output37.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-37] Anonymous FTP 비활성화(상) : 양호\n");
	else
		printf("[U-37] Anonymous FTP 비활성화(상) : 취약\n");

	system("rm -f output37.txt");
}
