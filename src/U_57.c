#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : 시스템 UMASK 값이 022 이상인지 아닌지 점검 
				UMASK 값이 022 이상이면 양호, 미만이만 취약. */

int U_57() {
	FILE* fp;
	char arr[BUF_SIZE];
	char setting[BUF_SIZE] = "UMASK=022";
	int ret;

	system("grep -r 'UMASK=022' /etc/profile > output57.txt");
	if ((fp = fopen("output57.txt", "r")) == NULL) {
		printf("[U-57] UMASK 설정 관리(중) : 점검 오류 (파일 탐색 불가)\n");
		system("rm -f output57.txt");
		return 0;
	}
	fgets(arr, sizeof(arr), fp);
	ret = strcmp(arr, setting);
	system("rm -f output57.txt");
	if (ret > 0){
		printf("[U-57] UMASK 설정 관리(중) : 양호\n");
		return 1;
	}
	else{
		printf("[U-57] UMASK 설정 관리(중) : 취약\n");
		return 2;
	}
}
