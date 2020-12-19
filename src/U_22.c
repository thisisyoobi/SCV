#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* cron 파일 소유자 및 권한 설정 */

void U_22()
{
	FILE *fp;
	struct stat buf;
	if((fp =fopen("/var/spool/cron/crontabs/*", "r")) == NULL){
		printf("[U-22] /var/spool/cron/crontabs/* 파일 소유자 및 권한 설정(상): 점검 오류\n");
		return;
	}
	
	stat("/var/spool/cron/crontabs/*", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf.st_mode &S_IRGRP){
			printf("[U-22] /var/spool/cron/crontabs/* 파일 소유자 및 권한 설정 (상) : 양호\n");
		}
		else
			printf("[U-22] /var/spool/cron/crontabs/* 파일 소유자 및 권한 설정 (상) : 취약\n");
		
	}
	else
		printf("[U-22] /var/spool/cron/crontabs/* 파일 소유자 및 권한 설정 (상) : 취약\n");
		
}
