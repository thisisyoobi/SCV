/*U_02 password complexity setting*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 6
#define LCREDIT "lcredit=-1\n"
#define UCREDIT "ucredit=-1\n"
#define DCREDIT "dcredit=-1\n"
#define OCREDIT "ocredit=-1\n"
#define MINLEN  "minlen=8\n"
#define RETRY   "retry=3\n"

char *DeleteSpace(char s[]);
int STRCMP(char* a, char* b);
void U_02()
{
	int success = 0;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/security/pwquality.conf", "r")) == NULL) {
		printf("File open error\n");
		exit(1);
	}

	while (fgets(buf, sizeof(buf), fp)) {
		if (STRCMP(DeleteSpace(buf), LCREDIT))
			success++;
		if (STRCMP(DeleteSpace(buf), UCREDIT))
			success++;
		if (STRCMP(DeleteSpace(buf), DCREDIT))
			success++;
		if (STRCMP(DeleteSpace(buf), OCREDIT))
			success++;
		if (STRCMP(DeleteSpace(buf), MINLEN))
			success++;
		if (STRCMP(DeleteSpace(buf), RETRY))
			success++;
	}

	if (success == SUCCESS)
		printf("[U-02] 패스워드 복잡성 설정 (상) : 양호\n");
	else
		printf("[U-02] 패스워드 복잡성 설정 (상) : 취약\n");
	fclose(fp);
}

char *DeleteSpace(char s[])
{
	char *str = (char *)malloc(strlen(s));
	int i, j = 0;
	for (i = 0; i<strlen(s); i++) {
		if (s[i] != ' ') {
			str[j] = s[i];
			j++;
		}
	}
	str[j] = 0;

	return str;
}

int STRCMP(char* a, char* b)
{
	if (strcmp(a, b) == 0)
		return 1;
	else
		return 0;
}
