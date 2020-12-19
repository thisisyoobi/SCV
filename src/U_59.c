#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 512
#define TRUE 1
#define FALSE 0

int U_59()
{
	FILE *fp;
	char buf[512];
	
	if( (fp = fopen("/etc/passwd", "r")) == NULL ) {
		printf("[U-59] 홈디렉토리로 지정한 디렉토리의 존재 관리 (중) : 점검 오류 (파일 탐색 불가)\n");
                return 0;
	}

	while( fgets(buf, LINE, fp) ) {
		int i = 0;
		int check = 0;
		while( check != 5 ) {
			if( buf[i] == ':' )
				check++;
			i++;
		}
		if( homeDir( buf, i )==FALSE ) {
		       	fclose(fp);
			printf("[U-59] 홈디렉토리로 지정한 디렉토리의 존재 관리 (중) : 취약\n");
			return 2;
		}
	}
	fclose(fp);
	printf("[U-59] 홈디렉토리로 지정한 디렉토리의 존재 관리 (중) : 양호\n");
	return 1;
}
	
