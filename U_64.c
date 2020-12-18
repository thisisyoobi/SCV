#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* Ftpusers 파일 소유자 및 권한 설정 */

void U_64()
{
	FILE *fp;
	struct stat buf;
	if((fp =fopen("/etc/ftpusers", "r")) == NULL){
		printf("[U-64] /etc/ftpusers 파일 소유자 및 권한 설정(하): 점검 오류\n");
		return;
	}
	
	stat("/etc/ftpusers", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf.st_mode &S_IRGRP){
			printf("[U-64] /etc/ftpusers 파일 소유자 및 권한 설정 (하) : 양호\n");
		}
		else
			printf("[U-22] /etc/ftpusers 파일 소유자 및 권한 설정 (하) : 취약\n");
		
	}
	else
		printf("[U-22] /var/spool/cron/crontabs/* 파일 소유자 및 권한 설정 (하) : 취약\n");
		
}
