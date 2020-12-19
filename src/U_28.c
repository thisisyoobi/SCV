#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define BUF_SIZE 1024

/* 점검기준 : NIS 서비스가 활성화 되어있는지 되어있지 않는지 점검 
				NIS 서비스 활성화시 취약, 비활성화시 양호.*/

int U_28() {
	FILE* fp;
	int n1;
	char count1[BUF_SIZE];
	char setting[BUF_SIZE] = "2";  /*( grep과 system call에의해서 2가 default )*/
	int ret1;

	system("ps -ef | egrep \"ypserv|ypbind|ypxfrd|rpc.yppasswdd|rpc.ypupdated\" | wc -l > output28.txt");

	if ((fp = fopen("output28.txt", "r")) == NULL) {
		printf("[U-28] NIS, NIS+ 점검(상) : 점검 오류 (파일 탐색 불가)\n");
		system("rm -f output28.txt");
		return 0;
	}

	fgets(count1, sizeof(count1), fp);
	ret1 = strcmp(count1, setting);
	system("rm -f output28.txt");
	if (ret1 == 10){
		printf("[U-28] NIS, NIS+ 점검(상) : 양호\n");
		return 1;
	}
	else{
		printf("[U-28] NIS, NIS+ 점검(상) : 취약\n");
		return 2;
	}

}
