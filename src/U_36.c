#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int U_36()
{
	int result = 1;
	int userCheckSum = 1;
	int groupCheckSum = 1;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/apache2/envvars", "r")) == NULL) {
		printf("[U-36] Apache 웹 프로세스 권한 제한 : 점검 오류\n");
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
			if(strstr(pLine, "export APACHE_RUN_USER="))
			{
				p = strtok(pLine, "=");
				p = strtok(NULL, "=");
				if(!strcmp(p, "root\n"))
					userCheckSum = 0;
			}
			
			if(strstr(pLine, "export APACHE_RUN_GROUP="))
			{
				p = strtok(pLine, "=");
				p = strtok(NULL, "=");
				if(!strcmp(p, "root\n"))
					groupCheckSum = 0;
			}

		}
	}
	fclose(fp);

	if(userCheckSum == 1 && groupCheckSum == 1)
	{
		printf("[U-36] Apache 웹 프로세스 권한 제한 : 양호\n");
		return 1;
	}
	else
	{
		printf("[U-36] Apache 웹 프로세스 권한 제한 : 취약\n");
		return 0;
	}

}
