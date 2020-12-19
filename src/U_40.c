#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int U_40()
{
	int result = 0;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/apache2/apache2.conf", "r")) == NULL) {
		printf("[U-40] Apache 파일 업로드 및 다운로드 제한 (상) : 점검 오류\n");
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
			if(strstr(pLine, "LimitRequestBody"))
			{
				if(strchr(pLine, '#'))
				{
					result = 0;
				}
				result = 1;
				break;
			}
		}
	}
	fclose(fp);

	if(result)
	{
		printf("[U-40] Apache 파일 업로드 및 다운로드 제한 (상) : 양호\n");
		return 1;
	}
	else
	{
		printf("[U-40] Apache 파일 업로드 및 다운로드 제한 (상) : 취약\n");
		return 2;
	}

}
