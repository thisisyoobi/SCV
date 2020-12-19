#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : r 계열 서비스 비활성화
				r 계열 서비스 활성화시 취약, 비활성화시 양호 */

void U_21() {
	FILE* fp1, * fp2;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "0";
	int ret;
	system("ls -alL /etc/xinetd.d/* 2> /dev/null| wc -l > output21_1.txt");
	if ((fp1 = fopen("output21_1.txt", "r")) == NULL) {
		printf("[U-21] r 계열 서비스 비활성화(상) : 점검 오류\n");
		return;
	}
	fgets(arr, sizeof(arr), fp1);
	ret = strcmp(arr, setting);
	// output21_1의 결과가 0이면 xinetd.d가 설치되지 않은것, 점검오류  
	if (ret == 10) {
		printf("[U-21] r 계열 서비스 비활성화(상) : 점검 오류\n"); // xinetd.d 설치 필요 ( sudo apt-get install xinetd.d ) 
		system("rm -f output21_1.txt");
		return;
	}
	else {
		system("ls -alL /etc/xinetd.d/* | egrep \"rsh|rlogin|rexec\" | egrep -v \"grep|klogin|kshell|kexec\" | wc -l > output21_2.txt");
		// 결과가 0이면 작동중이 아닌것 = > 양호 0이아니면 작동중, 취약
		if ((fp2 = fopen("output21_2.txt", "r")) == NULL) {
			printf("[U-21] r 계열 서비스 비활성화(상) : 점검 오류\n");
			return;
		}
		fgets(arr, sizeof(arr), fp2);
		ret = strcmp(arr, setting);
		if (ret == 10)
			printf("[U-21] r 계열 서비스 비활성화(상) : 양호\n");
		else
			printf("[U-21] r 계열 서비스 비활성화(상) : 취약\n");

		system("rm -f output21_1.txt");
		system("rm -f output21_2.txt");
	}
}
