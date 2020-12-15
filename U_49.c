#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define LP "lp"
#define UUCP "uucp"
#define NUUCP "nuucp"

void U_49() 
{
	FILE* fp;
	char buf[LINE];
	int check = 0;

	if((fp = fopen("/etc/passwd", "r")) == NULL) {
                printf("[U-49] 불필요한 계정 확인 (하) : 점검 오류\n");
                return;
        }

	while( fgets(buf, LINE, fp) ) {
		if( strncmp(buf, LP, 2) == 0 || 
				strncmp(buf, UUCP, 4) == 0 ||
				strncmp(buf, NUUCP, 5) == 0 )
			check++;
	}
	if(check > 0)
		printf("[U-49] 불필요한 계정 확인 (하) : 취약\n");
	else
		printf("[U-49] 불필요한 계정 확인 (하) : 양호\n");
}
