#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int U_35()
{
	int result = 1;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/apache2/apache2.conf", "r")) == NULL) {
		printf("[U-35] Apache 디렉토리 리스팅 제거 (상) : 점검 오류\n");
		return 0;
	}
	
	const int max = 9999;
	char line[max];
	char *pLine;
	char *p;
	while(!feof(fp))
	{
		pLine = fgets(line, max, fp);
		if(pLine)
		{
			if(strstr(pLine, "Options Indexes FollowSymLinks"))
			{
				if(strchr(pLine, '#'))
				{
					result = 1;
				}
				result = 0;
			}
		}
	}
	fclose(fp);

	if(result)
	{
		printf("[U-35] Apache 디렉토리 리스팅 제거 (상) : 양호\n");
		return 1;
	}
	else
	{
		printf("[U-35] Apache 디렉토리 리스팅 제거 (상) : 취약\n");
		return 2;
	}

}
