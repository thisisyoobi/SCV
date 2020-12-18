#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
/* 홈디렉토리 소유자 및 권한 설정 */

void U_58()
{
	FILE *fp;
	char buff[512];
	struct stat buf;
	if((fp =fopen("/etc/passwd", "r")) == NULL){
		printf("[U-58] 홈디렉토리 파일 소유자 및 권한 설정(중): 점검 오류\n");
		return;
	}
	while(fgets(buff, 512, fp)){
		int i=0;
		int check =0;
		while(check != 5){
			if(buff[i] == ':')
				check++;
			i++;
			}
		if( homeDir( buff, i )==0) {	
			stat(buff, &buf);
			if(buf.st_uid == 0){
				if(buf.st_mode & S_IWOTH && buf.st_mode & S_IWGRP){
					printf("[U-58] 홈디렉토리 소유자 및 권한 설정 (중) : 취약\n");
					exit(0);
				}
			}
		}
		}
	printf("[U-58] 홈디렉토리 소유자 및 권한 설정 (중) : 양호\n");
}



int homeDir(char s[], int index)
{
	char *home = "/home";
	int j = 0;

	for( int i=index; i<index+5; i++ ) {
		if( s[i] != home[j] ) {
			return 0;
		}
		j++;
	}
	return 1;	
}	
