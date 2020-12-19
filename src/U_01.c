#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// check /etc/securetty
int U_01_1()
{
	int result = 1;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/securetty", "r")) == NULL) {
		printf("[U-01] root 계정 원격 접속 제한 (상) : 점검 오류 (파일 탐색 불가)\n");
		return 0;
	}
	
	const int max = 9999;
	char line[max];
	char *pLine;
	char *pLine2;
	char *p;
	while(!feof(fp))
	{
		pLine = fgets(line, max, fp);
		if(pLine)
		{
			if(strstr(pLine, "pts"))
			{
				if(strchr(pLine, '#'))
					return result;
				else
				{
					result = 0;
					return result;
				}
			}
			else
				return result;
		}
	}
	fclose(fp);

	return result;
}

int U_01_2()
{
	int result = 1;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/pam.d/login", "r")) == NULL) {
		printf("[U-01] root 계정 원격 접속 제한 (상) : 점검 오류 (파일 탐색 불가)\n");
		result = 0;
		return result;
	}
	
	const int max = 9999;
	char line[max];
	char *pLine;
	while(!feof(fp))
	{
		pLine = fgets(line, max, fp);
		if(pLine)
		{
			if(strstr(pLine, "auth required /lib/security/pam_securetty.so"))
			{
				if(strchr(pLine, '#'))
				{
					result = 0;
					return result;
				}
				else
					return result;
			}
			else
			{
				result = 0;
				return result;
			}
		}
	}
	fclose(fp);

	return result;

}

void U_01()
{
	int result1;
	int result2;

	result1 = U_01_1();
	result2 = U_01_2();

	if (result1 == 1 && result2 == 1){
		printf("[U-01] root 계정 원격 접속 제한 (상) : 양호\n");
		return 1;
	}
	else{
		printf("[U-01] root 계정 원격 접속 제한 (상) : 취약\n");
		return 2;
	}
}
