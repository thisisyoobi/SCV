#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : FTP 서비스가 활성화 되어있는지 점검 */

void U_60() {
	FILE* fp1, * fp2;
	int n1, n2;
	char count1[BUF_SIZE], count2[BUF_SIZE];
	char checkarr[BUF_SIZE] = "2";
	int ret1, ret2;

	system("ps -ef | grep ftp | wc -l > output60_1.txt");
	system("ps -ef | egrep \"vsftpd|proftp\" | wc -l > output60_2.txt");
	if ((fp1 = fopen("output60_1.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	if ((fp2 = fopen("output60_2.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}

	fgets(count1, sizeof(count1), fp1);
	fgets(count2, sizeof(count2), fp2);

	ret1 = strcmp(count1, checkarr);
	ret2 = strcmp(count2, checkarr);

	if (ret1 == 10 && ret2 == 10)
		printf("[U-60] ftp 서비스 확인(하) : 양호\n");
	else
		printf("[U-60] ftp 서비스 확인(하) : 취약\n");

	system("rm -f output60_1.txt");
	system("rm -f output60_2.txt");

}
