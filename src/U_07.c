#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* /etc/passwd 파일 소유자 및 권한 설정 */

int U_07()
{
	FILE *fp; //변수 선언 
	struct stat buf;
	if((fp =fopen("/etc/passwd", "r")) == NULL){
		printf("[U-07] /etc/passwd 파일 소유자 및 권한 설정 (상) : 점검 오류 (파일 탐색 불가)\n");
		return 0;
	}
	stat("/etc/passwd", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf.st_mode &S_IRGRP && buf.st_mode &S_IROTH){
			printf("[U-07] /etc/passwd 파일 소유자 및 권한 설정 (상) : 양호\n");
			return 1;
		}
		else {
			printf("[U-07] /etc/passwd 파일 소유자 및 권한 설정 (상) : 취약\n");
			return 2;
		}
	}
	else
		printf("[U-07] /etc/passwd 파일 소유자 및 권한 설정 (상) : 취약\n");
	return 2;
}
