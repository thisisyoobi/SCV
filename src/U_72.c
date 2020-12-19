#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int U_72()
{
	int result1 = 0;
	int result2 = 0;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/apache2/apache2.conf", "r")) == NULL) {
		printf("[U-72] Apache 웹 서비스 정보 숨김 : 점검 오류\n");
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
			if(strstr(pLine, "ServerTokens Prod"))
			{
				if(strchr(pLine, '#'))
				{
					result1 = 0;
				}
				result1 = 1;
			}
			
			if(strstr(pLine, "ServerSignature Off"))
			{
				if(strchr(pLine, '#'))
				{
					result2 = 0;
				}
				result2 = 1;
			}

		}
	}
	fclose(fp);

	if(result1 && result2)
	{
		printf("[U-72] Apache 웹 서비스 정보 숨김 : 양호\n");
		return 1;
	}
	else
	{
		printf("[U-72] Apache 웹 서비스 정보 숨김 : 취약\n");
		return 0;
	}

}
