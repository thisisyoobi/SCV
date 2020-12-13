/*U_09 check PASS_MIN_DAYS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define PASS_MIN_DAYS "PASS_MIN_DAYS	1\n"

void U_09()
{
        FILE* fp;
        char buf[LINE];

        if((fp = fopen("/etc/login.defs", "r")) == NULL) {
                printf("File open error\n");
                exit(1);
        }

        while( fgets(buf, sizeof(buf), fp) ) {
                if( strcmp(PASS_MIN_DAYS, buf) == 0 ) {
                        printf("[U-09] 패스워드 최소 사용 기간 설정 (중) : 양호\n");
                        fclose(fp);
                        exit(0);
                }
        }
        printf("[U-09] 패스워드 최소 사용 기간 설정 (중) : 취약\n");
}

