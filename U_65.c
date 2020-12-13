#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : SNMP 서비스 구동 or 비구동 점검 */

void U_65() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";
	int ret1;

	system("ps -ef | grep snmp | wc -l > output65.txt");

	if ((fp = fopen("output65.txt", "r")) == NULL) {
		printf("open error!\n");
		exit(1);
	}
	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	if (ret1 == 10)
		printf("[U-65] SNMP 서비스 구동 점검(중) : 양호\n");
	else
		printf("[U-65] SNMP 서비스 구동 점검(중) : 취약\n");

	system("rm -f output65.txt");
}
