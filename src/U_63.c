#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : ftp 계정 shell 제한 점검 
				ftp 계정에대한 /bin/false 부여되었을시 양호, 되지않으면 취약. */

int U_63() {
	FILE* fp1, * fp2;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret;
	system("grep -r 'ftp' /etc/passwd | wc -l > output63_1.txt");
	if ((fp1 = fopen("output63_1.txt", "r")) == NULL) {
		printf("[U-63] ftp 계정 shell 제한(중) : 점검 오류 (파일 탐색 불가)\n");
		system("rm -f output63_1.txt");
		system("rm -f output63_2.txt");
		return 0;
	}
	fgets(arr, sizeof(arr), fp1);
	ret = strcmp(arr, setting);
	// output63_1의 결과가 0이면 ftp서비스 작동되지 않는것 -> 양호 print후 종료 
	if (ret == 10) {
		printf("[U-63] ftp 계정 shell 제한(중) : 양호\n");
		system("rm -f output63_1.txt");
		system("rm -f output63_2.txt");
		return 1;
	}
	else {
		system("grep -r 'ftp:x:500:100:Anonymous FTP USER:/var/ftp:/bin/false' /etc/passwd | wc -l > output63_2.txt");
		// 결과가 0이면 false 되있지 않다 -> 취약  .. 1이면 반대로, 양호
		if ((fp2 = fopen("output63_2.txt", "r")) == NULL) {
			printf("[U-63] ftp 계정 shell 제한(중) : 점검 오류 (파일 탐색 불가)\n");
			system("rm -f output63_1.txt");
		        system("rm -f output63_2.txt");
			return 0;
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting);
		system("rm -f output63_1.txt");
		system("rm -f output63_2.txt");
		if (ret == 10){
			printf("[U-63] ftp 계정 shell 제한(중) : 취약\n");
			return 2;
		}
		else{
			printf("[U-63] ftp 계정 shell 제한(중) : 양호\n");
			return 1;
		}

		system("rm -f output63_1.txt");
		system("rm -f output63_2.txt");
	}
}
