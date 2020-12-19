#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* at 파일 소유자 및 권한 설정 */

void U_66()
{
	FILE *fp;
	struct stat buf;
	if((fp =fopen("/etc/cron.d/at.allow", "r")) == NULL){
		printf("[U-66] /etc/cron.d/at.allow 파일 소유자 및 권한 설정(중): 점검 오류\n");
		return;
	}
	
	stat("/etc/cron.d/at.allow", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf.st_mode &S_IRGRP){
			printf("[U-66] /etc/cron.d/at.allow 파일 소유자 및 권한 설정 (중) : 양호\n");
		}
		else
			printf("[U-66] /etc/cron.d/at.allow 파일 소유자 및 권한 설정 (중) : 취약\n");
		
	}
	else
		printf("[U-66] /etc/cron.d/at.allow 파일 소유자 및 권한 설정 (중) : 취약\n");
		
}
