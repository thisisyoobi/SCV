#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void U_16()
{
	FILE* fp;
	char c;
	int check = 0;
	
	if( (fp = popen( "echo $PATH", "r" )) == NULL ) {
		printf("popen error\n");
		exit(1);
	}

	do {
		c = fgetc(fp);
		if( c == '.') {
			printf("[U-16] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 취약\n");
			pclose(fp);
			exit(0);
		}
		else if( c == ':')
			check++;
		else
			check = 0;

		if( check == 2 ) {
			printf("[U-16] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 취약\n");
			pclose(fp);
			exit(0);
		}
	} while( c != EOF );
 
	printf("[U-16] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 양호\n");
	pclose(fp);
}
