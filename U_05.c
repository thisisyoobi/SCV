/*U_05 Check if UID other than root is '0'*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 512

void U_05()
{
	FILE* fp;
	char buf[LINE];
	int check = 0;

	if((fp = fopen("/etc/passwd", "r")) == NULL) {
                printf("File open error\n");
                exit(1);
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
			printf("[U-02] root 이외의 UID가 '0' 금지 (중) : 취약\n");               
			fclose(fp);                        
			exit(0);                        
		}
		check = 0;
	}
	printf("[U-02] root 이외의 UID가 '0' 금지 (중) : 양호\n");
}
