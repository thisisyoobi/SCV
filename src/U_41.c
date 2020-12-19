#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int U_41()
{
	int result = 1;
	int count = 0;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/apache2/sites-available/000-default.conf", "r")) == NULL) {
		printf("[U-41] Apache 웹 서비스 영역의 분리 : 점검 오류\n");
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
			if(strstr(pLine, "DocumentRoot"))
			{
				count++;
				if(strstr(pLine, "/usr/local/apache/htdocs"))
				{
					if(strchr(pLine, '#'))
					{
						result = 1;
					}
					result = 0;
				}
				
				if(strstr(pLine, "/usr/local/apache2/htdocs"))
				{
					if(strchr(pLine, '#'))
					{
						result = 1;
					}
					result = 0;
				}
				
				if(strstr(pLine, "/var/www/html"))
				{
					if(strchr(pLine, '#'))
					{
						result = 1;
					}
					result = 0;
				}
			}
		}
	}
	fclose(fp);

	if(count == 0)
		result = 0;

	if(result)
	{
		printf("[U-41] Apache 웹 서비스 영역의 분리 : 양호\n");
		return 1;
	}
	else
	{
		printf("[U-41] Apache 웹 서비스 영역의 분리 : 취약\n");
		return 2;
	}

}
