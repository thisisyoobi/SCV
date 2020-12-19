#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define MINLEN  "minlen=8\n"

int U_46()
{
	FILE* fp;
	char buf[LINE];

	if((fp = fopen("/etc/security/pwquality.conf", "r")) == NULL) {
                printf("[U-46] 패스워드 최소길이 설정 (중) : 점검 오류 (파일 탐색 불가)\n");
                return 0;
        }
	
	while( fgets(buf, sizeof(buf), fp) ) {
		if( strcmp(MINLEN, DeleteSpace(buf)) == 0 ) {
			printf("[U-46] 패스워드 최소길이 설정 (중) : 양호\n");
			fclose(fp);
			return 1;
		}
	}
	printf("[U-46] 패스워드 최소길이 설정 (중) : 취약\n");
	fclose(fp);
	return 2;
}


