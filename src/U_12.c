#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* /etc/services 파일 소유자 및 권한 설정 */

void U_12()
{
	FILE *fp;
	struct stat buf;
	if((fp =fopen("/etc/services", "r")) == NULL){
		printf("[U-12] /etc/services 파일 소유자 및 권한 설정(상): 점검 오류\n");
		return;
	}
	
	stat("/etc/services", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf.st_mode &S_IRGRP && buf.st_mode &S_IROTH){
			printf("[U-12] /etc/services 파일 소유자 및 권한 설정 (상) : 양호\n");
		}
		else
			printf("[U-12] /etc/services 파일 소유자 및 권한 설정 (상) : 취약\n");
		
	}
	else
		printf("[U-12] /etc/passwd 파일 소유자 및 권한 설정 (상) : 취약\n");
		
}
