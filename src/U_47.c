#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define PASS_MAX_DAYS "PASS_MAX_DAYS	90\n"

int U_47()
{
        FILE* fp;
        char buf[LINE];

        if((fp = fopen("/etc/login.defs", "r")) == NULL) {
                printf("[U-47] 패스워드 최대 사용 기간 설정 (중) : 점검 오류 (파일 탐색 불가)\n");
                return 0;
        }

        while( fgets(buf, sizeof(buf), fp) ) {
                if( strcmp(PASS_MAX_DAYS, buf) == 0 ) {
                        printf("[U-47] 패스워드 최대 사용 기간 설정 (중) : 양호\n");
                        fclose(fp);
                        return 1;
                }
        }
        printf("[U-47] 패스워드 최대 사용 기간 설정 (중) : 취약\n");
        fclose(fp);
        return 2;
}
