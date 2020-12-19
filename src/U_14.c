#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
/* 사용자, 시스템 시작파일 및 환경파일 파일 소유자 및 권한 설정 */
extern int **environ;
int U_14()
{
	struct stat buf;
	for(int i=0; environ[i];i++){
		if(strcmp("environ[i]","HOME")){
			char *env = getenv("environ[i]");
		
			stat("env", &buf);
			if(buf.st_uid == 0){
				if(buf.st_mode &S_IWGRP || buf.st_mode &S_IWOTH){
					printf("[U-14] 사용자, 시스템 시작파일 소유자 및 권한 설정 (상) : 취약\n");
					return 2;
				}
			}
			else{
				printf("[U-14] 사용자, 시스템 시작파일 소유자 및 권한 설정 (상) : 취약\n");
				return 2;
				}
			}
	}
			printf("[U-14] 사용자, 시스템 시작파일 소유자 및 권한 설정 (상) : 양호\n");
			return 1;
}
