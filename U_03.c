#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void U_03()
{
	int result = 1;
	int CheckSum = 1;
	char buf[512];
	FILE* fp;
	int count = 0;

	if ((fp = fopen("/etc/login.defs", "r")) == NULL) {
		printf("[U-03] 계정 잠금 임계값 설정 : 점검 오류\n");
	}
	
	const int max = 9999;
	char line[max];
	char *pLine;
	char *p;
	int num = 0;

	while(!feof(fp))
	{
		pLine = fgets(line, max, fp);
		if(pLine)
		{
			if(strstr(pLine, "LOGIN_RETRIES"))
			{
				count++;
				p = strtok(pLine,"	");
				p = strtok(NULL,"	");
				num = atoi(p);
				if(num > 5)
					result = 0;
				break;
			}
		}
	}
	fclose(fp);

	if(count = 0)
		result = 0;

	if(CheckSum)
		printf("[U-03] 계정 잠금 임계값 설정 : 양호\n");
	else
		printf("[U-03] 계정 잠금 임계값 설정 : 취약\n");

}
