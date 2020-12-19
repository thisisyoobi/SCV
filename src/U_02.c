#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int STRCMP(char* a, char* b);
int U_02()
{
	int success = 0;
	char buf[512];
	FILE* fp;

	if ((fp = fopen("/etc/security/pwquality.conf", "r")) == NULL) {
		printf("[U-02] 패스워드 복잡성 설정 (상) : 점검 오류 (파일 탐색 불가)\n");
		return 0;
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

	if (success == 6) {
		printf("[U-02] 패스워드 복잡성 설정 (상) : 양호\n");
		fclose(fp);
		return 1;
	}
	else {
		printf("[U-02] 패스워드 복잡성 설정 (상) : 취약\n");
		fclose(fp);
		return 2;
	}
}


int STRCMP(char* a, char* b)
{
	if (strcmp(a, b) == 0)
		return 1;
	else
		return 0;
}
