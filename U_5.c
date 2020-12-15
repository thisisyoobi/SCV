#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void U_5()
{
	FILE* fp;
	char c;
	int check = 0;
	
	if( (fp = popen( "echo $PATH", "r" )) == NULL ) {
		printf("[U-5] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 점검 오류\n");
		return;
	}

	do {
		c = fgetc(fp);
		if( c == '.') {
			printf("[U-5] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 취약\n");
			pclose(fp);
			return;
		}
		else if( c == ':')
			check++;
		else
			check = 0;

		if( check == 2 ) {
			printf("[U-5] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 취약\n");
			pclose(fp);
			return;
		}
	} while( c != EOF );
 
	printf("[U-5] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 양호\n");
	pclose(fp);
}
