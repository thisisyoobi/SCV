#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int U_06()
{
        FILE *nouser_fp, *nogroup_fp;
	char buf[100];

        if( (nouser_fp = popen( "echo find / -nouser -print", "r" )) == NULL || (nogroup_fp = popen( "echo find / -nogroup -print", "r" )) == NULL ) {
                printf("[U-06] 파일 및 디렉터리 소유자 설정 (상) : 점검 오류 (파일 탐색 불가)\n");
                return 0;
        }
		
	if( fgets(buf, sizeof(buf), nouser_fp) != NULL || fgets(buf, sizeof(buf), nogroup_fp) != NULL ) {
		printf("[U-06] 파일 및 디렉터리 소유자 설정 (상) : 취약\n");
		pclose(nouser_fp);
		pclose(nogroup_fp);
		return 1;	
	}
	else {
		printf("[U-06] 파일 및 디렉터리 소유자 설정 (상) : 양호\n");
		pclose(nouser_fp);
		pclose(nogroup_fp);	
		return 2;
	}

}

