/*U_08 check PASS_MAX_DAYS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define PASS_MAX_DAYS "PASS_MAX_DAYS	90\n"

void U_08()
{
        FILE* fp;
        char buf[LINE];

        if((fp = fopen("/etc/login.defs", "r")) == NULL) {
                printf("File open error\n");
                exit(1);
        }

        while( fgets(buf, sizeof(buf), fp) ) {
                if( strcmp(PASS_MAX_DAYS, buf) == 0 ) {
                        printf("[U-08] 패스워드 최대 사용 기간 설정 (중) : 양호\n");
                        fclose(fp);
                        exit(0);
                }
        }
        printf("[U-08] 패스워드 최대 사용 기간 설정 (중) : 취약\n");
}
