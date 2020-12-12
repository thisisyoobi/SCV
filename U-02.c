#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*점검 기준 : 최소 9자리 이상 되어야 하며 숫자,대문자,소문자,특수문자 최소 1개 포함*/
#define SUCCESS 6
#define LCREDIT "lcredit = -1\n"
#define UCREDIT "ucredit = -1\n"
#define DCREDIT "dcredit = -1\n"
#define OCREDIT "ocredit = -1\n"
#define MINLEN  "minlen = 8\n"
#define RETRY   "retry = 3\n"

int STRCMP(char* a, char* b);
void U_02()
{	
	int success = 0;
	char buf[512];
	FILE* fp;

	if((fp = fopen("/etc/security/pwquality.conf", "r")) == NULL) {
		printf("File open error\n");
		exit(1);
	}

	while( fgets(buf, sizeof(buf), fp) ) {
		if(STRCMP(buf, LCREDIT))
			success++;
		if(STRCMP(buf, UCREDIT))
			success++;
		if(STRCMP(buf, DCREDIT))
			success++;
		if(STRCMP(buf, OCREDIT))
			success++;
		if(STRCMP(buf, MINLEN))
			success++;
		if(STRCMP(buf, RETRY))
			success++;
	}
		
	if(success == SUCCESS)
      		printf("[U-02] 패스워드 복잡성 설정 (상) : 양호\n");
	else
		printf("[U-02] 패스워드 복잡성 설정 (상) : 취약\n");
	fclose(fp);
}

int STRCMP(char* a, char* b)
{
	if(strcmp(a, b) == 0)
		return 1;
	else
		return 0;
}
