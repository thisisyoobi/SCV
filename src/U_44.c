#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 512

void U_44()
{
	FILE* fp;
	char buf[LINE];
	int check = 0;

	if((fp = fopen("/etc/passwd", "r")) == NULL) {
                printf("[U-44] root 이외의 UID가 '0' 금지 (중) : 점검 오류\n"); 
                return;
    }

	fgets(buf, sizeof(buf), fp);
	while( fgets(buf, sizeof(buf), fp) ) {
		int i = 0;
		while (check != 2) {
			if(buf[i] == ':') {
				check++;
			}
			i++;
		}
		if(buf[i] == '0') {
			printf("[U-44] root 이외의 UID가 '0' 금지 (중) : 취약\n");               
			fclose(fp);                        
			return;                   
		}
		check = 0;
	}
	printf("[U-44] root 이외의 UID가 '0' 금지 (중) : 양호\n");
}
