#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void U_65()
{
	int result = 1;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/ftpusers", "r")) == NULL) {
		printf("[U-65] ftpusers 파일 설정 : 점검 오류\n");
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
			if(strstr(pLine, "root"))
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
		printf("[U-65] ftpusers 파일 설정 : 양호\n");
	else
		printf("[U-65] ftpusers 파일 설정 : 취약\n");

}
