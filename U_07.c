/*U_07 check minimum password length*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define MINLEN  "minlen=8\n"

char *DeleteSpace(char s[]);
void U_07()
{
	FILE* fp;
	char buf[LINE];

	if((fp = fopen("/etc/security/pwquality.conf", "r")) == NULL) {
                printf("File open error\n");
                exit(1);
        }
	
	while( fgets(buf, sizeof(buf), fp) ) {
		if( strcmp(MINLEN, DeleteSpace(buf)) == 0 ) {
			printf("[U-07] 패스워드 최소길이 설정 (중) : 양호\n");
			fclose(fp);
			exit(0);
		}
	}
	printf("[U-07] 패스워드 최소길이 설정 (중) : 취약\n");
}

char *DeleteSpace(char s[])
{
        char *str = (char *)malloc(strlen(s));
        int i, j = 0;
        for(i = 0; i<strlen(s);i++) {
                if(s[i] != ' ') {
                        str[j] = s[i];
                        j++;
                }
        }
        str[j] = 0;

        return str;
}


