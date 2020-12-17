#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : NIS 서비스 비활성화
    ( 뭐가 불필요한지 몰라서 일단 활성화되면 취약, 없으면 양호로 구현함 )  */

void U_56() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2"; /*( grep과 system call에의해서 2가 default )*/
	int ret1;

	system("ps -ef | grep yp | wc -l > output56.txt");

	if ((fp = fopen("output56.txt", "r")) == NULL) {
		printf("[U-56] NIS 서비스 비활성화(중) : 점검 오류\n");
		return;
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-56] NIS 서비스 비활성화(중) : 양호\n");
	else
		printf("[U-56] NIS 서비스 비활성화(중) : 취약\n");

	system("rm -f output56.txt");
}
