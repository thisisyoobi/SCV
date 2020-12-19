#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* NFS 설정파일 접근권한 */

int U_70()
{
	FILE *fp; //변수 선언 
	struct stat buf;
	if((fp =fopen("/etc/exports", "r")) == NULL){
		printf("[U-70] NFS 설정파일 접근권한 (중) : 점검 오류(파일 탐색 불가)\n");
		return 0;
	}
	stat("/etc/exports", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR && buf.st_mode &S_IRGRP && buf.st_mode &S_IROTH){
			printf("[U-70] NFS 설정파일 접근권한 (중) : 양호\n");
			return 1;
		}
		else
			printf("[U-70] NFS 설정파일 접근권한 (중) : 취약\n");
			return 2;
	}
	else
		printf("[U-70] NFS 설정파일 접근권한 (중) : 취약\n");
		return 2;
}
