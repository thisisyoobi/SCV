#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define PASS_MIN_DAYS "PASS_MIN_DAYS	1\n"

int U_48()
{
        FILE* fp;
        char buf[LINE];

        if((fp = fopen("/etc/login.defs", "r")) == NULL) {
                printf("[U-48] 패스워드 최소 사용 기간 설정 (중) : 점검 오류 (파일 탐색 불가)\n");
                return 0;
        }

        while( fgets(buf, sizeof(buf), fp) ) {
                if( strcmp(PASS_MIN_DAYS, buf) == 0 ) {
                        printf("[U-48] 패스워드 최소 사용 기간 설정 (중) : 양호\n");
                        fclose(fp);
                        return 1;
                }
        }
        printf("[U-48] 패스워드 최소 사용 기간 설정 (중) : 취약\n");
        fclose(fp);
        return 2;
}

