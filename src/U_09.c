#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
/* /etc/hosts 파일 소유자 및 권한 설정 */

int U_09()
{
	FILE *fp;
	struct stat buf;
	if((fp =fopen("/etc/hosts", "r")) == NULL){
		printf("[U-09] /etc/host 파일 소유자 및 권한 설정 (상) : 점검 오류 (파일 탐색 불가)\n");
		return 0;
	}
	
	stat("/etc/hosts", &buf);
	if(buf.st_uid == 0){
		if(buf.st_mode &S_IRUSR && buf.st_mode &S_IWUSR){
			printf("[U-09] /etc/host 파일 소유자 및 권한 설정 (상) : 양호\n");
			return 1;
		}
		else
			printf("[U-09] /etc/host 파일 소유자 및 권한 설정 (상) : 취약\n");
			return 2;
	}
	else{
		printf("[U-09] /etc/host 파일 소유자 및 권한 설정 (상) : 취약\n");
		return 2;
	}
}
