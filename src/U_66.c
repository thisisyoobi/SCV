#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* at 파일 소유자 및 권한 설정 */

int U_66()
{
	FILE *fp;
	struct stat buf;
	if((fp =fopen("/etc/cron.d/at.allow", "r")) == NULL){
		printf("[U-66] at 파일 소유자 및 권한 설정(중): 점검 오류(파일 탐색 불가)\n");
		return 0;
	}
	
	stat("/etc/cron.d/at.allow", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf.st_mode &S_IRGRP){
			printf("[U-66] at 파일 소유자 및 권한 설정 (중) : 양호\n");
			return 1;
		}
		else
			printf("[U-66] at 파일 소유자 및 권한 설정 (중) : 취약\n");
			return 2;
	}
	else
		printf("[U-66] at 파일 소유자 및 권한 설정 (중) : 취약\n");
		return 2;
}
