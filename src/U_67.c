#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : SNMP 서비스 구동 or 비구동 점검
				SNMP 서비스 비 사용시 양호, 사용시 취약 */

void U_67() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2"; /*( grep과 system call에의해서 2가 default )*/
	int ret1;

	system("ps -ef | grep snmp | wc -l > output67.txt");

	if ((fp = fopen("output67.txt", "r")) == NULL) {
		printf("[U-67] SNMP 서비스 구동 점검(중) : 점검 오류\n");
		return;
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-67] SNMP 서비스 구동 점검(중) : 양호\n");
	else
		printf("[U-67] SNMP 서비스 구동 점검(중) : 취약\n");

	system("rm -f output67.txt");
}
