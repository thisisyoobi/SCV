#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* /etc/syslog.conf 파일 소유자 및 권한 설정 */
// commit change1
int U_11()
{
	FILE *fp;
	struct stat buf;
	
	if((fp =fopen("/etc/syslog.conf", "r")) == NULL){
		printf("[U-11] /etc/syslog.conf 파일 소유자 및 권한 설정(상): 점검 오류(파일 탐색 불가)\n");
		return 0;
	}
	stat("/etc/syslog.conf", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf.st_mode &S_IRGRP && buf.st_mode &S_IROTH){
			printf("[U-11] /etc/syslog.conf 파일 소유자 및 권한 설정 (상) : 양호\n");
			return 1;
		}
		else
			printf("[U-11] /etc/syslog.conf 파일 소유자 및 권한 설정 (상) : 취약\n");
			return 2;
	}
	else{
		printf("[U-11] /etc/syslog.conf 파일 소유자 및 권한 설정 (상) : 취약\n");
		return 2;
	}
}
