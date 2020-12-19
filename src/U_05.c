#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int U_05()
{
	FILE* fp;
	char c;
	int check = 0;
	
	if( (fp = popen( "echo $PATH", "r" )) == NULL ) {
		printf("[U-05] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 점검 오류 (파일 탐색 불가)\n");
		return 0;
	}

	do {
		c = fgetc(fp);
		if( c == '.') {
			printf("[U-05] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 취약\n");
			pclose(fp);
			return 2;
		}
		else if( c == ':')
			check++;
		else
			check = 0;

		if( check == 2 ) {
			printf("[U-05] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 취약\n");
			pclose(fp);
			return 2;
		}
	} while( c != EOF );
 
	printf("[U-05] root 홈, 패스 디렉터리 권한 및 패스 설정 (상) : 양호\n");
	pclose(fp);
	return 1;
}
