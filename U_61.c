#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : ftp 계정 shell 제한 점검 */

void U_61() {
	FILE* fp1, * fp2;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret;
	system("grep -r 'ftp' /etc/passwd | wc -l > output61_1.txt");
	// output61_1의 결과가 0이면 ftp서비스 작동되지 않는것 -> 양호 print후 종료 
	if ((fp1 = fopen("output61_1.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(arr, sizeof(arr), fp1);
	ret = strcmp(arr, setting);
	if (ret == 10) {
		printf("[U-61] ftp 계정 shell 제한(중) : 양호\n");
		system("rm -f output61_1.txt");
	}
	else {
		system("grep -r 'ftp:x:500:100:Anonymous FTP USER:/var/ftp:/bin/false' /etc/passwd | wc -l > output61_2.txt");
		// 결과가 0이면 false 되있지 않다 -> 취약  .. 1이면 반대로, 양호
		if ((fp2 = fopen("output61_2.txt", "r")) == NULL) {
			printf("open error!\n");
			exit(1);
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting);
		if (ret == 10)
			printf("[U-61] ftp 계정 shell 제한(중) : 취약\n");
		else
			printf("[U-61] ftp 계정 shell 제한(중) : 양호\n");

		system("rm -f output61_2.txt");
	}
}
